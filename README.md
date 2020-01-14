# Universal-Robot-UR5-Controller
This package is developed to enable the control of a UR5 Robot.
# Getting Started
Here, Gazebo is used for simulation of UR5 robot. Which is available at https://github.com/ros-industrial/universal_robot.git
# Prerequisites
ROS installed Machine + Gazebo Simulator
# Test Environment
Ubuntu 16.04.6 LTS (Xenial) + ROS Kinetic

# Installation & Setup
1. Install and build  ros-industrial/universal_robot from, https://github.com/ros-industrial/universal_robot.git ( make sure your package is installed in /opt/ros/kinetic and not locally.)
2. Creat a new workspace in your local directory. eg.(universalbot_ws)
3. Simply clone this repository in your new worksapce with, https://github.com/amjack0/Universal-Robot-UR5-Controller.git and build the package with catkin_make. look out for errors !
3. After building the package, don't forget to source with, eg. source/universalbot_ws/devel/setup.bash

# Running the simulation
1. roslaunch ur_gazebo ur5.launch , this will bring your ur5 robot model on gazebo.
2. roslaunch force_pub urm_robot_controller.launch , this will launch your controller.
3. rosrun force_pub force1_node 50 20 , by running this command we are starting our force publisher which publishes force in X,Y and Z by passing frequency and amplitude as an argument respectively.
4. rosrun force_pub tcp_node , this node will publishe the messages on wrist_3_joint (End effector of UR5).

By running these command will enable our endeffector_frc_trq_controller to control the joints, in this repo we are only controlling wrist_3_joint & wrist_2_joint with effort_controllers/JointEffortController. 

Discussion: Results can be improved by further tuning the PID values for joints. This was not attempted due to the time contraint.

# Acknowledgments
http://gazebosim.org/tutorials/?tut=ros_control#Tutorial:ROSControl \
http://wiki.ros.org/ros_control/Tutorials
