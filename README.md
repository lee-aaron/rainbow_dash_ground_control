# [ROS] Ground Control for the Rainbow Dash Rover

Yonder Dynamics, 2017

## Install Dependencies

##### Required ROS Packages:
[joystick_drivers](https://github.com/ros-drivers/joystick_drivers)
[roslibjs](https://github.com/RobotWebTools/roslibjs)
[rosbridge-server](sudo apt-get install ros-<rosdistro>-rosbridge-server)

##### Terminal Dependencies

`sudo apt install libusb-dev libspnav-dev libbluetooth-dev libcwiid-dev`

##### Setting up Ground Station as the master roscore
Find your IP with:
`hostname -I` (case sensitive)

add the following to your ~/.bashrc:
```
export ROS_IP=<IP>
export ROS_HOSTNAME=<IP>
export ROS_MASTER_URI=http://<IP>:11311
```

and then:
`source ~/.bashrc`

## Run

```
cd ~/catkin_ws
catkin_make
roslaunch rainbow_dash_ground_control xbox_control.launch
```


