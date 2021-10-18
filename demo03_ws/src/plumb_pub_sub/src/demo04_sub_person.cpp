#include "ros/ros.h"
#include "plumb_pub_sub/Person.h"

void doPerson(const plumb_pub_sub::Person::ConstPtr& person) {
    ROS_INFO("subscribed person: %s, %d, %2f",
        person->name.c_str(), person->age, person->height
    );
    
}

int main(int argc, char *argv[])
{
    ROS_INFO("subscriber");
    ros::init(argc, argv, "Person_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe(
        "chat", 10, doPerson
    );
    ros::spin();
    return 0;
}
