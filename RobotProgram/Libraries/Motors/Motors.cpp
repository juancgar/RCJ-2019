#include "Motors.h"

Motors::Motors(Motor RF, Motor LF, Motor LB, Motor RB)
{
  this->RF = RF;
  this->LF = LF;
  this->LB = LB;
  this->RB = RB;
  Power = 0;
}
void Motors::Stop()
{
  RF.Stop();
  LF.Stop();
  LB.Stop();
  RB.Stop();
}
void Motors::Forward(int Power) {
  RF.MotorSetA(Power);
  LF.MotorSetA(Power);
  LB.MotorSetA(Power);
  RB.MotorSetA(Power);
}

void Motors::Backward(int Power) {
  RF.MotorSetB(Power);
  LF.MotorSetB(Power);
  LB.MotorSetB(Power);
  RB.MotorSetB(Power);
}

void Motors::Left(int Power)
{
  RF.MotorSetA(Power);
  LF.MotorSetB(Power);
  LB.MotorSetA(Power);
  RB.MotorSetB(Power);

}
void Motors::Right(int Power)
{
  RF.MotorSetB(Power);
  LF.MotorSetA(Power);
  LB.MotorSetB(Power);
  RB.MotorSetA(Power);

}

void Motors::TurnRight(int Power)
{
  RF.Stop();
  LF.MotorSetA(Power);
  LB.MotorSetA(Power);
  RB.Stop();

}
void Motors::TurnLeft(int Power)
{
  RF.MotorSetA(Power);
  LF.Stop();
  LB.Stop();
  RB.MotorSetA(Power);
}
