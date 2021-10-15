#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
/*
    publisher
*/

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "publisher");
    ros::NodeHandle nh; 
    ros::Publisher pub = nh.advertise<std_msgs::String>(
        "topic_content", 10);

    std_msgs::String msg;

    // public frequence
    ros::Rate rate(10);
    int count = 0;
    while (ros::ok)
    {
        count++;
        std::stringstream ss;
        ss << "hello ---> " << count;
        msg.data = ss.str();
        pub.publish(msg);
        // log out
        ROS_INFO("data published: %s", ss.str().c_str());
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
