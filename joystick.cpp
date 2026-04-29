#include <Arduino.h>
#include "joystick.h"

void JoyStick::setup() {

  pinMode(JoyStick_Z, INPUT);

};

void JoyStick::readValues() {
  
  // reads the values between 0 - 1023
  x = analogRead(JoyStick_X);
  y = analogRead(JoyStick_Y);

  // reading a bool that has its value flipped
  z = digitalRead(JoyStick_Z);
  z = !z;

};