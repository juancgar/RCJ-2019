
#include "Motor.h"

Motor::Motor()
{
  pinA=NULL;
  pinB=NULL;
  pinPWM =NULL;
  Power =0;

}
Motor::Motor(int pinA,int pinB,int pinPWM)
{
  this->pinA=pinA;
  this->pinB=pinB;
  this->pinPWM = pinPWM;
  Power = 0;

  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinPWM,OUTPUT);
  
  
}
void Motor::MotorSetA(int Power)
{
  digitalWrite(pinA,LOW);
  digitalWrite(pinB,HIGH);
  analogWrite(pinPWM,Power);
}
void Motor::MotorSetB(int Power)
{
  digitalWrite(pinB,LOW);
  digitalWrite(pinA,HIGH);
  analogWrite(pinPWM,Power);
}

void Motor::Stop()
{
  digitalWrite(pinB,LOW);
  digitalWrite(pinA,LOW);
  analogWrite(pinPWM,0);
}
