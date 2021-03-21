#include "ros/ros.h"
#include <std_msgs/Int64.h>
#include <sstream>

void callback1(const std_msgs::Int64::ConstPtr& square)
{
ROS_INFO("%d",square->data);
}

int main(int argc,char **argv)
{
ros::init(argc,argv, "printnum");
ros::NodeHandle n;
ros::Subscriber sub =n.subscribe("printnum",1000,callback1);
ros::spin();

return 0;
}
