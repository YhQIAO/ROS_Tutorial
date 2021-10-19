#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "getParam_c");
    ros::NodeHandle nh;

    double radius = nh.param("radius", 0.5);
    ROS_INFO("查询的结果为 radius = %.2f", radius);

    double radius2 = 0;
    bool result = nh.getParam("radius", radius2);
    if(result) {
        ROS_INFO("获取的半径是：%.2f", radius2);
    } else {
        ROS_INFO("not find !");
    }

    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &name:names) {
        ROS_INFO("遍历的元素:%s", name.c_str());
    }

    

    return 0;
}
