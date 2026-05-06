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

void RobotArm::changePositon(int x1, int y1, int z1, int x2, int y2, int z2) {

  Serial.print(positionGripper);
  Serial.print(",");
  Serial.print(z1);
  Serial.print(",");
  Serial.print(z2);
  Serial.println();

  positionBase = stickMove(x1, positionBase, 180, 0);
  positionShoulder = stickMove(y1, positionShoulder, 165, 15);
  positionElbow = stickMove(y2, positionElbow, 180, 0);
  positionWristVer = stickMove(x2, positionWristVer, 180, 0);
  positionGripper = stickClick(z1, z2, positionGripper, 73, 10);

  Braccio.ServoMovement(positionDelay, positionBase, positionShoulder, positionElbow, positionWristRot, positionWristVer, positionGripper);

};

int RobotArm::stickClick(int stick1, int stick2, int positionSection, int maxDegree, int minDegree) {

  if(stick1 == 1) {

    positionSection++ ;

    if(positionSection >= maxDegree) {

      positionSection = 73;

    };

  };

  if(stick2 == 1) {

    positionSection-- ;

    if(positionSection <= minDegree) {

      positionSection = 10;

    };

  };

  return positionSection;

};

int RobotArm::stickMove(int n, int positionSection, int maxDegree, int minDegree) {

  if (n >= (511 + 128)) {

    positionSection += 10;

    if (positionSection >= maxDegree) {

      positionSection = maxDegree;

    };

  };

  if (n <= (511 - 128)) {

    positionSection -= 10;

    if (positionSection <= minDegree) {

      positionSection = minDegree;

    };

  };

  return positionSection;

};