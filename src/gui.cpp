#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float32MultiArray.h"
#include <vector>
#include <sstream>

void sCallback(const std_msgs::String::ConstPtr& msg) {

}

int main(int argc, char **argv) {
  ros::init(argc, argv, "gui");
  
  ros::NodeHandle n;


  //ros::Subscriber sub = n.subscribe("joy", 1000, joyCallback);
  //ros::Publisher pubDir = n.advertise<std_msgs::Float32>("UpDown", 1000);


  while (ros::ok()) {
    ros::spinOnce();
  }

  return 0;
}
