#!/bin/sh
#xterm  -e  "  roslaunch turtlebot_gazebo turtlebot_world.launch " &

xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/PROJECT-5-HOME-SERVICE-ROBOT/catkin_ws/src/map/myworld.world" &

sleep 25
xterm -e " roslaunch turtlebot_gazebo gmapping_demo.launch" &
#xterm  -e  "  rosrun gmapping slam_gmapping " & 
sleep 20
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 20
xterm -e "  roslaunch turtlebot_teleop keyboard_teleop.launch "
