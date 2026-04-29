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

void RobotArm::changePositon(int x, int y, int z) {

  positionBase = stickClick(z, positionBase);

  Braccio.ServoMovement(positionDelay, positionBase, positionShoulder, positionElbow, positionWristRot, positionWristVer, positionGripper);

};

int RobotArm::stickClick(int z, int positionBase) {

  Serial.println(z);
  Serial.println(positionBase);

  if(z == 1 && isStickCLickAdding) {

    positionBase ++;

    if(positionBase >= 180) {

      isStickCLickAdding = false;

    };

  };

  if(z == 1 && !isStickCLickAdding) {

    positionBase --;

    if(positionBase <= 0) {

      isStickCLickAdding = true;

    };

  };

  return positionBase;

};