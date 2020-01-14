#include <ros/ros.h>
#include <geometry_msgs/Wrench.h>
//#include <std_msgs/Float64.h>

using namespace std;

geometry_msgs::Wrench data;
ros::Subscriber frc_sub;

void my_callback(const geometry_msgs::Wrench::ConstPtr& msg){
	data.force.x = msg->force.x;
	data.force.y = msg->force.y;
	data.force.z = msg->force.z;
	data.torque.x = msg->torque.x;
	data.torque.y = msg->torque.y;
	data.torque.z = msg->torque.z;
	ROS_INFO("Debug x output: %f", msg->force.x);
    	//ROS_INFO("Debug y output: %f", msg->force.y);
    	//ROS_INFO("Debug z output: %f", msg->force.z);
}

int main(int argc, char **argv)
{  
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher wrench_pub = n.advertise<geometry_msgs::Wrench>("/urbot/endeffector_frc_trq_controller/command", 1000);
  ros::Rate loop_rate(10);
  frc_sub = n.subscribe("force1", 1000, my_callback);
  //std_msgs::Float64 my_message;
  int count = 0;

  while (ros::ok())
  {
    //my_message.data = data;
    wrench_pub.publish(data);
    ROS_INFO("Debug Publish x output: %f", data.force.x);
    //ROS_INFO("Debug Publish y output: %f", data.force.y);
    //ROS_INFO("Debug Publish z output: %f", data.force.z);
    ros::spinOnce();
    loop_rate.sleep();
    count++;
  }
  return 0;
}
