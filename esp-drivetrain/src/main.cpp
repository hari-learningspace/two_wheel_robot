
#include "main.h"
#include "robot.h"
#include <geometry_msgs/Pose.h>

// RaspberryPi host address. Default ROS port is 11411
// IPAddress server(192, 168, 0,ROS_HOST); // Set the rosserial socket server IP
// address const uint16_t serverPort = ROS_PORT; // Set the rosserial socket
// server port

// Define the node handle to roscore
ros::NodeHandle nh;
bool nodeHandleCreated = false;

// Define a variable to hold the Pose message
geometry_msgs::Pose pose_msg;

TwoWheeledRobot *robot;

// Subscriber definition
ros::Subscriber<geometry_msgs::Pose> *sub_pose;

// Create matrix to hold the command input
// X position, Y position, Orientation
float refPose[3] = {0.0, 0.0, 0.0};
const byte X_POS = 0;
const byte Y_POS = 1;
const byte PSI = 2;

// Error matrix for feedback loop
float poseError[3] = {0.0, 0.0, 0.0};

// Set callback flag

bool commandCalled = false;

//--------------------------------------------//
// Command callback
//--------------------------------------------//
void commandCb(const geometry_msgs::Pose &cmd) {

  // Print the new pose command message to the ROS console
  // ROSLOGString("Received X, Y, Psi");
  // ROSLOGString(cmd.position.x, cmd.position.y, cmd.orientation.y);

  // Get the robot's current pose
  float *currentPose = 0; // robot->getLocalPose();

  // Print the robot's current pose to the ROS console
  // robot->driveTrain.printLocalPose();

  // Assign new target pose. Current state + new pose.
  refPose[X_POS] = currentPose[X_POS] + cmd.position.x;
  refPose[Y_POS] = currentPose[Y_POS] + cmd.position.y;
  refPose[PSI] =
      currentPose[PSI] + cmd.orientation.y / (180 / PI); // in radians

  // Print target pose to the ROS console
  // ROSLOGString("Target Pose X, Y, Psi");
  // ROSLOG3F(refPose[X_POS], refPose[Y_POS], refPose[PSI]);

  // Set the commandCalled flag
  commandCalled = true;
}

void setup() {
  // Connect to WiFi
  // connectWiFi();

  // Initialize the ROS nodehandle.
  // nh.getHardware()->setConnection(server, serverPort);

  // Starting node
  nh.initNode();
  nodeHandleCreated = true;
  delay(1000);

  // Setup subscriber with callback function to receive the command
  sub_pose = new ros::Subscriber<geometry_msgs::Pose>("/pose_cmd", commandCb);
  nh.subscribe(*sub_pose);

  robot = new TwoWheeledRobot(&nh);
}

void loop() {
  // Loop until command is sent.
  if (commandCalled) {

    // Position control loop
    // robot->poseController(refPose);

    // Reset commandCalled flag
    commandCalled = false;
  }

  // Wait for subscribed messages
  if (nodeHandleCreated) {
    nh.spinOnce();
  }
  delay(1000);
}