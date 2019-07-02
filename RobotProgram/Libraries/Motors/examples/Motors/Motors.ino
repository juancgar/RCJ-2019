#include "Motors.h"

Motor RF(8,10,9);
Motor LF(13,11,12);
Motor LB(5,7,6);
Motor RB(24,22,3);

Motors robot(RF,LF,LB,RB);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  robot.Forward(100);
  /*
  robot.Stop();
  robot.Backward(100);
  robot.Left(100);
  robot.Right(100);
  robot.TurnRight(100);
  robot.TurnLeft(100);
  
  */
}
