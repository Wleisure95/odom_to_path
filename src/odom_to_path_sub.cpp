#include "ros/ros.h"
#include "std_msgs/String.h"
#include<tf/transform_broadcaster.h>  
#include<nav_msgs/Odometry.h>  
#include<geometry_msgs/Twist.h>     
#include<geometry_msgs/PoseWithCovarianceStamped.h>  
#include<math.h>  
#include<stdio.h>  
#include<vector>  
#include<iostream>  
#include <nav_msgs/Path.h>
using namespace std;

nav_msgs::Path path;
geometry_msgs::PoseStamped pose;
void odom_pathshow(const nav_msgs::Odometry& odom_data)
{
  path.header= odom_data.header;
  pose.header = odom_data.header;
	pose.pose = odom_data.pose.pose;
	path.poses.push_back(pose);
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "odom_to_path");

	ros::NodeHandle n;

  ros::Publisher  pub = n.advertise<nav_msgs::Path>("odom_path", 1000,true);
	ros::Subscriber sub = n.subscribe("/odom", 1000, &odom_pathshow);
    
	
	/**
	 * ros::spin() will enter a loop, pumping callbacks.  With this version, all
	 * callbacks will be called from within this thread (the main one).  ros::spin()
	 * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
	 */
  ros::Rate r(10.0);
	while(ros::ok())
	{
		pub.publish(path);
    ros::spinOnce();
    r.sleep();
	}

	return 0;
}
