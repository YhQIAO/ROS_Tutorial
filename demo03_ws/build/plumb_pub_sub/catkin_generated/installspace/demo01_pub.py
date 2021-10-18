#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("py_Publisher")
    pub = rospy.Publisher("topic_content", String, queue_size=10)

    msg = String()
    count = 0
    rate = rospy.Rate(10) # 指定发布频率
    while not rospy.is_shutdown():
        msg.data = "hello"+str(count)
        pub.publish(msg)
        count += 1
        rate.sleep()
