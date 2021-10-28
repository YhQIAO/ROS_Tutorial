#include "ros/ros.h"
#include <turtlesim/Spawn.h>


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "service_call");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>(
        "/spawn"
    );

    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";

    client.waitForExistence(); // 判断服务器状态，每启动泽挂起
    if(client.call(spawn)) {
        ROS_INFO("request success");
        ROS_INFO("new turtle is: %s", spawn.response.name.c_str());
    } else {
        ROS_INFO("resquest failed");
    }

    return 0;
}
