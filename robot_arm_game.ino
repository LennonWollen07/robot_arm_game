#include "joystick.h"
#include "robot_arm.h"

// get the classes
JoyStick stick1 = JoyStick(0, 1, 8);
JoyStick stick2 = JoyStick(2, 3, 13);
RobotArm arm = RobotArm();

void setup() {

  Serial.begin(9600);
  stick1.setup();
  stick2.setup();
  arm.setup();
  
};

void loop() {

  // reads the 3 values of the joysticks
  stick1.readValues();
  stick2.readValues();
  arm.changePositon(stick1.x, stick1.y, stick1.z, stick2.x, stick2.y, stick2.z);
  
};