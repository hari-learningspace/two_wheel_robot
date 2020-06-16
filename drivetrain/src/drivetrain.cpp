#include "drivetrain.h"

// ------------------ Constructor ---------------------------------
DriveTrain::DriveTrain(ros::NodeHandle *nodeHandle) : nh_(nodeHandle) {
  // Attach robot to the global odometry frame
  state.header.frame_id = "/odom";     // Global odometry frame
  state.child_frame_id = "/base_link"; // Robot local frame

  // Setup publisher to report current state
  pub_odom = new ros::Publisher("/odom", &state);
  nh_->advertise(*pub_odom);
  // instances[0] = this;
  // Start state update timer
  // const esp_timer_create_args_t periodic_timer_args = {.callback =
  // &updateStateISR}; esp_timer_create(&periodic_timer_args,
  // &stateUpdateTimer);
  // esp_timer_start_periodic(stateUpdateTimer,updatePeriodMicros); // Time in
  // milliseconds (50)
}
