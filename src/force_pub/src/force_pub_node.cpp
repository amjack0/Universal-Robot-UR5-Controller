#include <unistd.h>
#include <ros/ros.h>
#include <geometry_msgs/Wrench.h>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char **argv)
{  
  ros::init(argc, argv, "talker1");
  ros::NodeHandle n;
  ros::Publisher wrench_pub = n.advertise<geometry_msgs::Wrench>("force1", 1000);
  ros::Rate loop_rate(10);
  int count = 0;
  int frequency = atoll(argv[1]);
  int amp = atoll(argv[2]);
  cout << frequency <<endl;
  cout << amp <<endl;
  while (ros::ok())
  {
    geometry_msgs::Wrench msgForce1;
    	
	    msgForce1.force.x = amp*sin(frequency*count);
	    msgForce1.force.y = amp*sin(frequency*count);
	    msgForce1.force.z = amp*sin(frequency*count);
	    msgForce1.torque.x = amp*sin(frequency*count);
	    msgForce1.torque.y = amp*sin(frequency*count);
	    msgForce1.torque.z = amp*sin(frequency*count);

    //ROS_INFO("Debug output fr: %d", frequency);
    /*ROS_INFO("Debug output: %f", msgForce1.force.x);
    ROS_INFO("Debug output: %f", msgForce1.force.y);
    ROS_INFO("Debug output: %f", msgForce1.force.z);
	*/
    wrench_pub.publish(msgForce1);
    ros::spinOnce();
    loop_rate.sleep();
      count++;
  }

  return 0;
}
