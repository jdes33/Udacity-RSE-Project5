#!/bin/sh

### This script launces the turtlebot in my world, opens rviz and then makes robot go to picup zone, wait 5 seconds, then makes robot return to dropoff zone

# launch turtlebot (in my world)
xterm -e "source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../map/myworld.world" &
sleep 5

# launch amcl
xterm -e "source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/../map/map.yaml" &
sleep 5

# launch rviz
xterm  -e  "source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5

# launch pick_objects
xterm  -e  "source $(pwd)/../../devel/setup.bash; rosrun pick_objects pick_objects " 


