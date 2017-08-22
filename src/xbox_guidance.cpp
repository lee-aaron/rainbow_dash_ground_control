#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Joy.h"

#include <sstream>


void joyCallback(const sensor_msgs::Joy) {


}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "xbox_guidance");
  
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("joy", 1000, joyCallback);
  ros::Publisher pub = n.advertise<std_msgs::String>("xbox_guidance", 1000);

  ros::spin();

  return 0;
}
