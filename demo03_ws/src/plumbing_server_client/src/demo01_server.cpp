#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

bool doNums(plumbing_server_client::AddInts::Request &request,
            plumbing_server_client::AddInts::Response &response){
    // 处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到的请求数据：num1 = %d, num2 = %d", num1, num2);
    int sum = num1+num2;
    response.sum = sum;
    ROS_INFO("求和结果: sum = %d", sum);
    // 组织相应
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
   
    ros::init(argc, argv, "demo01_server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("addInts", doNums);
    ROS_INFO("服务器端启动");
    ros::spin();;   
    return 0;
}
