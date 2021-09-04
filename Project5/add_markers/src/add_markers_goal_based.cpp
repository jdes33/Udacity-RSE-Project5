#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers_goal_based");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

	std::string object_location;

  // Set our shape type to be a cylinder
  uint32_t shape = visualization_msgs::Marker::CYLINDER;

	visualization_msgs::Marker marker;
	// Set the frame ID and timestamp.  See the TF tutorials for information on these.
	marker.header.frame_id = "map";
	marker.header.stamp = ros::Time::now();

	// Set the namespace and id for this marker.  This serves to create a unique ID
	// Any marker sent with the same namespace and id will overwrite the old one
	marker.ns = "add_markers_goal_based";
	marker.id = 0;

	// Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
	marker.type = shape;

	// Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
	marker.action = visualization_msgs::Marker::ADD;

	// Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
	// set marker position to pickup zone
	marker.pose.position.x = 1.5;
	marker.pose.position.y = 4.5;
	marker.pose.position.z = 0;
	marker.pose.orientation.x = 0.0;
	marker.pose.orientation.y = 0.0;
	marker.pose.orientation.z = 0.0;
	marker.pose.orientation.w = 1.0;

	// Set the scale of the marker -- 1x1x1 here means 1m on a side
	marker.scale.x = 0.2;
	marker.scale.y = 0.2;
	marker.scale.z = 0.2;

	// Set the color -- be sure to set alpha to something non-zero!
	marker.color.r = 0.0f;
	marker.color.g = 0.0f;
	marker.color.b = 255.0f;
	marker.color.a = 1.0;

	// no value passed to Duration so will never auto delete
	marker.lifetime = ros::Duration();

  // Publish the marker
  while (marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
    {
      return 0;
    }
    ROS_WARN_ONCE("Please create a subscriber to the marker");
    sleep(1);
  }
  marker_pub.publish(marker);

	// wait for robot to reach 
	while(object_location != "robot"){
		n.getParam("object_location", object_location);
	}

	// delete marker
	marker.action = visualization_msgs::Marker::DELETE;
	marker_pub.publish(marker);


	// wait until reached dropoff zone
	while(object_location != "dropoff zone"){
		n.getParam("object_location", object_location);
	}


	marker.action = visualization_msgs::Marker::ADD;
	marker.lifetime = ros::Duration();
	// set marker position to dropoff zone
	marker.pose.position.x = -2.0;
	marker.pose.position.y = 0;

  // Publish the marker
  while (marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
    {
      return 0;
    }
    ROS_WARN_ONCE("Please create a subscriber to the marker");
    sleep(1);
  }
  marker_pub.publish(marker);


	while(ros::ok()){
		if(!ros::ok()){
			return 0;
		}
		sleep(1);
	}

	return 0;
}
