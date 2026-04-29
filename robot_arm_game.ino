#include "joystick.h"
#include "robot_arm.h"

// get the classes
JoyStick stick = JoyStick();
RobotArm arm = RobotArm();

void setup() {

  Serial.begin(9600);
  stick.setup();
  arm.setup();
  
};

void loop() {

  // reads the 3 values of the joystick
  stick.readValues();
  arm.changePositon(stick.x, stick.y, stick.z);
};