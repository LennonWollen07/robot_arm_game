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

  positionBase = stickClick(z, positionBase, 180, 0);
  positionShoulder = stickMove(y, positionShoulder, 165, 15);
  positionElbow = stickMove(y, positionElbow, 180, 0);
  positionGripper = stickMove(x, positionGripper, 73, 10);

  Braccio.ServoMovement(positionDelay, positionBase, positionShoulder, positionElbow, positionWristRot, positionWristVer, positionGripper);

};

int RobotArm::stickClick(int n, int positionSection, int maxDegree, int minDegree) {

  if(n == 1 && isStickCLickAdding) {

    positionSection ++;

    if(positionSection >= maxDegree) {

      isStickCLickAdding = false;

    };

  };

  if(n == 1 && !isStickCLickAdding) {

    positionSection --;

    if(positionSection <= minDegree) {

      isStickCLickAdding = true;

    };

  };

  return positionSection;

};

int RobotArm::stickMove(int n, int positionSection, int maxDegree, int minDegree) {

  if (n >= (511 + 128)) {

    positionSection ++;

    if (positionSection >= maxDegree) {

      positionSection = maxDegree;

    };

  };

  if (n <= (511 - 128)) {

    positionSection --;

    if (positionSection <= minDegree) {

      positionSection = minDegree;

    };

  };

  return positionSection;

};