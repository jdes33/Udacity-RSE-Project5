#!/bin/sh

#launch given world
#xterm  -e  "  roslaunch turtlebot_gazebo turtlebot_world.launch " &

# launch my world
# note: could`ve used `rospack find` instead of pwd if the world file was in a package
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../map/myworld.world" &

sleep 25
xterm -e " roslaunch turtlebot_gazebo gmapping_demo.launch" &
#xterm  -e  "  rosrun gmapping slam_gmapping " & 
sleep 20
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 20
xterm -e "  roslaunch turtlebot_teleop keyboard_teleop.launch "
