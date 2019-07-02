#ifndef Motor_H
#define Motor_H
#include <Arduino.h>
class Motor
{
  public:
    //Constructores
    Motor();
    Motor(int pinA,int pinB,int pinPWM);
  void MotorSetA(int PWM);
    void MotorSetB(int PWM);
    void Stop();
  private:
    int pinA;
    int pinB;
    int pinPWM;
    int Power;
};
#endif
