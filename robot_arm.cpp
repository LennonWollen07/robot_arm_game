#include <Arduino.h>
#include <Braccio.h>
#include <Servo.h>
#include "robot_arm.h"

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

void RobotArm::setup() {

  Braccio.begin();

};

void RobotArm::changePositon() {

  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 73);

};