#include "ros/ros.h"

/*
    实现参数的新增与修改
*/

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "setParam_c");
    ros::NodeHandle nh;
    // 实现参数的新增
    // nodehandle
    nh.setParam("type", "XiaoHuang");
    nh.setParam("radius", 0.15);

    // ros::param
    ros::param::set("type_param", "XiaoBai");
    ros::param::set("radius_param", 0.15);

    // 参数修改
    nh.setParam("radius", 0.2);
    ros::param::set("radius_param", 0.25);
    return 0;
}
