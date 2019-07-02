
#include <Arduino.h>
//4 motor library
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