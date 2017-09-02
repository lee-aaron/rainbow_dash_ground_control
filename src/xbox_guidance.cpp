#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float32MultiArray.h"
#include "sensor_msgs/Joy.h"
#include <vector>

#include <sstream>

/*
0: 
1:
2:
3: [DRIVE] Turn intensity (1 to -1)
4: [DRIVE] Velocity intensity (1 to -1)
5:

...

*/
std::vector<float> controls(23,0.0);
int diff;

void joyCallback(const sensor_msgs::Joy::ConstPtr& msg) {

/*

Indexes of axes in msg->data.axes
0: Left Stick (LS) LeftRight 
1: Left Stick (LS) UpDown 
2: Left Trigger (LT)
3: Right Stick (RS) LeftRight 
4: Right Stick (RS) UpDown 
5: Right Trigger (RT)
6: D-Pad (DP) LeftRight 
7: D-Pad (DP) UpDown

Indexes of buttons in msg->data.buttons
0: A
1: B
2: X
3: Y
4: Left Bumper (LB)
5: Right Bumper (RB)
6: BACK Button
7: START Button
8: XBOX Button
9: LS Click
10: RS Click
11: DP Left
12: DP Right
13: DP Up
14: DP Down


Axis values range from 1.0 to -1.0:

For the D-Pad, 0 is unpressed, -1 is down/right, 1 is up/left

For the triggers, 1 is unpressed, -1 is fully pressed

For the sticks, -1 is down/right, 1 is up/left, 0 is untouched

*/

  // Right Stick
  float lr, ud;
  lr=msg->axes[3];
  ud=msg->axes[4];
 
  // Right Stick Safe Zones
  //lr=(abs(lr)<0.1)?0:lr;
  //ud=(abs(ud)<0.1)?0:ud;

  // Set Controls
  lr=truncf(lr*10)/10;
  ud=truncf(ud*10)/10;

  if( controls[3] != lr ) {
    controls[3] = lr;
    diff=1;
  }
  if( controls[4] != ud ) {
    controls[4] = ud;
    diff=1;
  }
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "xbox_guidance");
  
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("joy", 1000, joyCallback);
  ros::Publisher pub = n.advertise<std_msgs::Float32MultiArray>("manual_guidance", 1000);
  ros::Publisher pubDir = n.advertise<std_msgs::Float32>("UpDown", 1000);

  std_msgs::Float32MultiArray controlData = std_msgs::Float32MultiArray();
  std_msgs::Float32 val = std_msgs::Float32();

  while (ros::ok()) {
    controlData.data=controls;

    if(diff) {
       pub.publish(controlData);
       diff=0; 
    }
    
    if( val.data != controls[4] ) {
      val.data=controls[4];
      pubDir.publish(val);
    }
    ros::spinOnce();
  }

  return 0;
}
