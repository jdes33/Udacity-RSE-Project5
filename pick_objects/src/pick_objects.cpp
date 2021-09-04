#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>



// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

	// nodehandle to communicate with ROS master to set parameter
	ros::NodeHandle nh;
	// set a parameter called object_location to pickup_zone
	nh.setParam("object_location", "pickup zone");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

// MAKE ROBOT MOVE TO PICKUP ZONE

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 1.5;
	goal.target_pose.pose.position.y = 4.5;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal (pickup zone location)");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, the base moved to the pickup zone!");
		// robot "picks up" object so set object_location parameter to "robot" 
		nh.setParam("object_location", "robot");
  }else{
    ROS_INFO("The base failed to move to the pickup zone.");

}
	// wait for 5 seconds
	ros::Duration(5.0).sleep();

	
	// MAKE ROBOT MOVE TO SECOND POSITION



  // set up the frame parameters
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = -2.0;
	goal.target_pose.pose.position.y = 0.0;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal (dropoff zone location)");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, the base moved to the dropoff zone!");
		nh.setParam("object_location", "dropoff zone");
  }else{
    ROS_INFO("The base failed to move to the dropoff zone.");
	}

	while(ros::ok()){
		if(!ros::ok()){
			return 0;
		}
		ros::Duration(1).sleep();
	}
	return 0;
}
