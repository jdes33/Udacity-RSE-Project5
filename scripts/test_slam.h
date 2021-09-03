#!/bin/sh

# launch my world
# note: could`ve used `rospack find` instead of pwd if the world file was in a package
xterm -e " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../map/myworld.world" &
sleep 25

# launch gmapping
xterm -e " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 20

# launch rviz
xterm  -e  " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 20

# launch teleop
xterm -e " source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_teleop keyboard_teleop.launch "
