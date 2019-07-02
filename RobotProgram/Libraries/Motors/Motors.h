#ifndef Motors_H
#define Motors_H

#include <Arduino.h>
#include "Motor.h"
//4 motor library
class Motors
{
  public:
    
    Motors(Motor RF, Motor LF, Motor LB, Motor RB);

    void Forward(int Power);
    void Backward(int Power);
    void Left(int Power);
    void Right(int Power);

    void Stop();

    void TurnRight(int Power);
    void TurnLeft(int Power);

  private:
    Motor RF;
    Motor LF;
    Motor LB;
    Motor RB;
    int Power;

};
#endif
