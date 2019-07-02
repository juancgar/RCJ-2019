#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#ifndef _Compass_H_
#define _Compass_H_
const int id = 0x01;
  int TestValue;
  int Uno;
  int Dos;
  int compass;
  
void ReadCompassSensor() {
  //this code lets the arduino know you want to talk to the compass Sensor
  Wire.beginTransmission(id);
  Wire.write(0x44);
  Wire.endTransmission();

  //the code below requests 2 bytes of information and then combines them
  //to make a number 0-360 that it saves in the variable TestValue
  Wire.requestFrom(id, 2);
  while (Wire.available() < 2);
  byte lowbyte = Wire.read();
  byte highbyte = Wire.read();
  TestValue = word(highbyte, lowbyte);
}
void compassBegin() {
  Wire.begin();  //turn on i2c
  Wire.beginTransmission(id);
  Wire.write(0x00);
  Wire.endTransmission();
  while (Wire.available() > 0)
    Wire.read();
  ReadCompassSensor();
  Uno = TestValue;
}

int getDirection()
{
  ReadCompassSensor();
  Dos = TestValue - Uno;
  if (Dos < 0) {
    compass = Dos + 359;
  }
  else {
    compass = Dos;
  }
  return (compass);
}
#endif