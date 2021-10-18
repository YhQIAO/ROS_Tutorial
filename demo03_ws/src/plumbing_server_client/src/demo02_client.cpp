#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    if(argc != 3) {
        ROS_INFO("提交参数个数不对");
        return 1;
    }

    ros::init(argc, argv, "demo02_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient
        <plumbing_server_client::AddInts>("addInts");
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    client.waitForExistence();

    bool flag = client.call(ai);
    if(flag == true) {
        ROS_INFO("相应成功");
        ROS_INFO("相应结果 = %d", ai.response.sum);
    } else {
        ROS_INFO("处理失败");
    }
    return 0;
}
