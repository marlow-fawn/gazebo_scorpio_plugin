//
// Created by mfawn on 7/6/20.
//

#include "ros/ros.h"
#include "geometry_msgs/Point.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "pointNode");
    ros::NodeHandle n;
    ros::Publisher point_pub = n.advertise< geometry_msgs::Point>("pointTopic", 1000);
    ros::Rate loop_rate(10);

    geometry_msgs::Point p;
    p.x = 1;
    p.y = 2;
    p.z = 3;

    while (ros::ok()) {
        point_pub.publish(p);
        ros::spinOnce();
        loop_rate.sleep();
    }
}