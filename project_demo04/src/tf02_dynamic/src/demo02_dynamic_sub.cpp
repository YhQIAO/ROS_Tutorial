#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "dynamic_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "turtle1";
    ps.header.stamp = ros::Time(0.0);
    ps.point.x = 1;
    ps.point.y = 2.0;
    ps.point.z = 0.0;

    // ros::Duration(2).sleep();

    ros::Rate rate(10);
    while(ros::ok) {

        try{
            geometry_msgs::PointStamped ps_out =  buffer.transform(ps, "world");
            ROS_INFO("transformed point is : %.2f, %.2f, %.2f",
                ps_out.point.x, ps_out.point.y, ps_out.point.z);

            rate.sleep();
            ros::spinOnce();
        } catch(const std::exception& e) {
            ROS_INFO("transform information not subscribed");
        }
    }

    return 0;
}
