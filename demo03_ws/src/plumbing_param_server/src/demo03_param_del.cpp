#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "param_del_c");
    ros::NodeHandle nh;

    bool flag1 = nh.deleteParam("radius");
    if(flag1) {
        ROS_INFO("delete success");
    } else {
        ROS_INFO("delete failed");
    }
    return 0;
}
