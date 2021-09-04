# Udacity-RSE-Project5

The purpose of this project was to utilise ROS' navigation stack to make a turtlebot plan a path to an object, move to the object (as if it were picking up the object) and then moving to another location to drop off the object.

The following are the packages I imported and utilised:

 - gmapping: performs SLAM to build a map of the environment
 - turtlebot_telop: for controlling the manually (for testing purposes)
 - turtlebot_gazebo: to deploy a turtlebot in the world I created and to launch an amcl demo (utilises adaptive monte carlo localization and djikstra's algorithm to navigate around the map)
 - turtlebot_rviz_launchers: for loading up an rviz file that was setup to display appropriate features during navigation of turtlebot (map, path of robot...)

The following are packaged I created:

 - pick_objects: for sending goals to the navigation stack (sending pickup and drop off locations and using parameter server to update status of object)
 - add_markers: for displaying the object as a marker (a blue cylinder) at the pickup and drop off zones (uses parameter server to get status of object to do this)


# Here are some images showing navigation (run the home_service.sh script to see this in action):
### First the robot moves to the pickup location to obtain the object (object is blue).
![Alt text](media/moving_to_object.png?raw=true "moving_to_object")
### After picking it up, the robot waits 5 seconds then begins to travel to the drop off location.
![Alt text](media/carrying_object.png?raw=true "carrying_object")
### Once it reaches the drop off location it puts the object down.
![Alt text](media/dropping_object.png?raw=true "dropping_object")
