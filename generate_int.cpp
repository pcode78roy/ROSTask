#include "ros/ros.h"
#include <std_msgs/Int64.h>
#include <sstream>


int main(int argc, char **argv)
{
ros::init(argc, argv,"generate_int");
ros::NodeHandle n;
ros::Publisher chatter_pub=n.advertise<std_msgs::Int64>("initial",1000);
ros::Rate loop_rate(1);

int count=0;
while(ros::ok())
{

std_msgs::Int64 num;
num.data=count;
ROS_INFO("%d",num.data);
chatter_pub.publish(num);
ros::spinOnce();
loop_rate.sleep();
++count;
}
return 0;
}
