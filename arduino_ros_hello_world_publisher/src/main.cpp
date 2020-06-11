#include <Arduino.h>
#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[] = "helloworld";

void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.advertise(chatter);
}

void loop() {
  // put your main code here, to run repeatedly:
  str_msg.data = hello;
  chatter.publish(&str_msg);
  nh.spinOnce();
  delay(1000);
}