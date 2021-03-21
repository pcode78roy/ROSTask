#include "ros/ros.h"
#include<std_msgs/Int64.h>
#include <sstream>


void chatterCallback(const std_msgs::Int64::ConstPtr& num)

{
while(ros::ok())
{

ROS_INFO("%d",num->data);
std_msgs::Int64 square;
square.data = (num->data*num->data);
ros::NodeHandle n;
ros::Publisher   print_pub = n.advertise<std_msgs::Int64>("printnum",1000);
ROS_INFO(" %d", square.data);
print_pub.publish(square);
ros::spinOnce();
ros::Rate loop_rate(1);
loop_rate.sleep();

}
  
}

int main(int argc, char **argv)
{

  ros::init(argc,argv,  "square");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("initial" , 1000 ,chatterCallback );
ros::spin();

  return 0;
}
