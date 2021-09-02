#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 20
xterm  -e  " rosrun gmapping slam_gmapping " & 
sleep 20
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 20
xterm -e " roslaunch turtlebot_teleop keyboard_teleop.launch "
