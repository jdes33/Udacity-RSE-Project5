#!/bin/sh

### This script launces the turtlebot in my world, opens rviz, you can then publish a point for the robot to plan a path and move to (using the 2D nav goal button in rviz)

# launch world file 
xterm -e " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../map/myworld.world" &
sleep 5

# amcl demo
xterm -e " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/../map/map.yaml" &
sleep 5

# view navigation
xterm  -e  " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch " 
