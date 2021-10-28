#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "param_server");

    ros::NodeHandle nh("turtlesim");
    nh.setParam("background_r", 255);
    

    ros::param::set("/turtlesim/background_r",255);
    ros::param::set("/turtlesim/background_g",255);
    ros::param::set("/turtlesim/background_b",255);
    return 0;
}
