#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr &msg) {
    ROS_INFO("message received : %s", msg->data.c_str());
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle  nh;
    ros::Subscriber sub = nh.subscribe(
        "topic_content", 10, doMsg
    );
    ros::spin();
    return 0;
}
