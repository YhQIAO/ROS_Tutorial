#include "ros/ros.h"
#include "plumb_pub_sub/Person.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "Person_publisher");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumb_pub_sub::Person>(
        "chat", 10
    );
    plumb_pub_sub::Person person;
    person.name = "cxn";
    person.age = 22;
    person.height = 1.66;
    ros::Rate rate(1);
    while(ros::ok) {
        person.age +=1;
        pub.publish(person);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
