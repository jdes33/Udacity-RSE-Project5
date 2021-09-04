#!/bin/sh

# launch world file 
xterm -e " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../map/myworld.world" &
sleep 5

# amcl demo
xterm -e " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/../map/map.yaml" &
sleep 5

# view navigation
xterm  -e  " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch " 
