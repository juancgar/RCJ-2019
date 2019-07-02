#include <Motor.h>




Motor RF(8,10,9);
Motor LF(13,11,12);
Motor LB(5,7,6);
Motor RB(24,22,3);

void paro()
{
RF.Stop();
LF.Stop();
LB.Stop();
RB.Stop();
}
void adelante() {
RF.MotorSetA(100);
LF.MotorSetA(100);
LB.MotorSetA(100);
RB.MotorSetA(100);
}

void atras() {
RF.MotorSetB(100);
LF.MotorSetB(100);
LB.MotorSetB(100);
RB.MotorSetB(100);
}

void izquierda()
{
RF.MotorSetA(100);
LF.MotorSetB(100);
LB.MotorSetA(100);
RB.MotorSetB(100);
  
}
void derecha()
{
RF.MotorSetB(100);
LF.MotorSetA(100);
LB.MotorSetB(100);
RB.MotorSetA(100);
  
}

void giroderecha()
{
  RF.Stop();
  LF.MotorSetA(100);
  LB.MotorSetA(100);
  RB.Stop();
  
}
void giroizquierda()
{
RF.MotorSetA(100);
LF.Stop();
LB.Stop();
RB.MotorSetA(100);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
derecha();
delay(500);
paro();
}
