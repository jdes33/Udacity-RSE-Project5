#!/bin/sh

### This script launces the turtlebot in my world, opens rviz and dispays the marker at pickup zone until robot gets to it, makes robot wait 5 seconds at pickup zone, makes robot plan a path to the dropoff zone, then it shows the marker at drop off zone when robot gets there

# launch turtlebot (in my world)
xterm -e "source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../map/myworld.world" &
sleep 5

# launch amcl
xterm -e "source $(pwd)/../../devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/../map/map.yaml" &
sleep 5

# launch rviz
xterm  -e  "source $(pwd)/../../devel/setup.bash; rosrun rviz rviz -d $(pwd)/../rvizConfig/home_service.rviz " &
sleep 10

# launch pick_objects
xterm  -e  "source $(pwd)/../../devel/setup.bash; rosrun pick_objects pick_objects " &

# launch add_markers
xterm  -e  "source $(pwd)/../../devel/setup.bash; rosrun add_markers add_markers_goal_based " 

