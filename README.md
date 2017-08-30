# [ROS] Ground Control for the Rainbow Dash Rover

Yonder Dynamics, 2017

## Install Dependencies

#### Required ROS Packages:
[joystick_drivers](https://github.com/ros-drivers/joystick_drivers)

#### Terminal Dependencies

`sudo apt install libusb-dev libspnav-dev libbluetooth-dev libcwiid-dev`

## Run

```
cd ~/catkin_ws
catkin_make
roslaunch rainbow_dash_ground_control xbox_control.launch
```
