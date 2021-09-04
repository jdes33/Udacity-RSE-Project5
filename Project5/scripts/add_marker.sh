#!/bin/sh

### This script launces the turtlebot in my world and opens rviz. Once you manually add a marker to rviz it then displays marker (blue cylinder) at pickup zone, waits 5 seconds, hides the marker for 5 seconds and then displays at dropoff zone indefinitely)

# launch turtlebot (in my world)
xterm -e "source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../map/myworld.world" &
sleep 5

# launch amcl
xterm -e "source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/../map/map.yaml" &
sleep 5

# launch rviz
xterm  -e  "source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5

# launch add_markers
xterm  -e  "source $(pwd)/../../devel/setup.bash; rosrun add_markers add_markers " 

