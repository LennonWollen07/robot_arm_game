#include <Arduino.h>
#include "joystick.h"

JoyStick::JoyStick(int JoyStick_X, int JoyStick_Y, int JoyStick_Z) {

  this->JoyStick_X = JoyStick_X;
  this->JoyStick_Y = JoyStick_Y;
  this->JoyStick_Z = JoyStick_Z;

};

void JoyStick::setup() {

  pinMode(JoyStick_Z, INPUT);

};

void JoyStick::readValues() {
  
  // reads the values between 0 - 1023
  x = analogRead(JoyStick_X);
  y = analogRead(JoyStick_Y);

  z = digitalRead(JoyStick_Z);
  z = !z;
};