#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

def doMsg(msg):
    rospy.loginfo("info sub: %s", msg.data)


if __name__ == "__main__":
    rospy.init_node("Py_subscriber")
    sub = rospy.Subscriber("topic_content", String,doMsg,queue_size=10)
    rospy.spin() # 不要忘记这个
