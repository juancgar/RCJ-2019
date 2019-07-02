#include <Ultra.h>

#include <Motor.h>

//Programa para que el robot pueda guardar check points
//Utilización de un programa predictivo
//Librerias dieñadas por Juan Carlos Garza López

Motor A(10,8,9);
Motor B(13,11,12);
Motor C(7,5,6);
Motor D(22,24,3);


Ultra ULTB(49,47);
Ultra ULTI(48,46);
Ultra ULTD(41,39);

void paro()
{
A.Stop();
B.Stop();
C.Stop();
D.Stop();
}
void adelante() {
A.MotorSetA(100);
B.MotorSetA(100);
C.MotorSetA(100);
D.MotorSetA(100);
}

void atras() {
A.MotorSetB(100);
B.MotorSetB(100);
C.MotorSetB(100);
D.MotorSetB(100);
}

void izquierda()
{
A.MotorSetA(100);
B.MotorSetB(100);
C.MotorSetA(100);
D.MotorSetB(100);
  
}
void derecha()
{
A.MotorSetB(100);
B.MotorSetA(100);
C.MotorSetB(100);
D.MotorSetA(100);
  
}

void giroderecha()
{
  A.Stop();
  B.MotorSetA(100);
  C.MotorSetA(100);
  D.Stop();
  
}
void giroizquierda()
{
A.MotorSetA(100);
B.Stop();
C.Stop();
D.MotorSetA(100);
}

//variables globales

void setup() {
  Serial.begin(9600);
  
  

}

void loop() {

  Seral.println(ULTI.getDistance());
  ULTD.getDistance();

}
