
#include <Pixy2.h>
#include <Wire.h>

#include <Ultra.h>
#include <Motor.h>






Ultra ULTI(49,47);
Ultra ULTB(48,46);
Ultra ULTD(41,39);






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

int flags[3] = {0,0,0};
///diferencia del sensor derecho
int ultD;
int ultDTemp = 0;
int DifD = 0;
//diferencia del sensor izquierdo
int ultI;
int ultITemp = 0;
int DifI = 0;
///sensor de atras ultrasonico
int ultB;
int ultBTemp = 0;
int DifB = 0;



int dos;
int compas;



int compassAddress = 0x01; //we got this from I2C Scanner
int TestValue;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 Wire.begin();  //turn on i2c
  Wire.beginTransmission(compassAddress); //open communication to sensor 
  Wire.write(0x00); //blank packetbm
  Wire.endTransmission(); //close communication
  while(Wire.available() > 0)
     Wire.read();
 ultD = ULTD.getDistance();
 ultI = ULTI.getDistance();
 ultB = ULTI.getDistance();
 
}

void loop() {

  ReadCompassSensor();


  static int uno = TestValue;


dos = uno - TestValue;

if (dos < 0){
  compas = dos +360;
}
else {
  compas = dos;
}
  //sensor ultrasonico derecho
  ultDTemp = ultD;
  ultD = ULTD.getDistance();
  //sensor ultrasonico izquierdo
  ultITemp = ultI;
  ultI = ULTI.getDistance();
  //sensor ultrasonico de atras
  ultBTemp = ultB;
  ultB = ULTB.getDistance();
  
  
 // Serial.print(ultD);
  //Serial.print(" ");
  DifD = abs(ultD-ultDTemp);
  //Serial.print(DifD);
  //Serial.print(" ");

  //Serial.print(ultI);
  //Serial.print(" ");
  DifI = abs(ultI-ultITemp);
  //Serial.println(DifI);
  DifB= abs(ultB-ultBTemp);


  if(DifI > 20 && !flags[0])
  {
    flags[0]++;
  }
  else if(DifI > 15 && flags[0])
  {
    flags[0]--;
  }
  
  
  if(DifD > 20 && !flags[1])
  {
    flags[1]++;
  }
  else if(DifD > 15 && flags[1])
  {
    flags[1]--;
  }
   
   
  if(DifB > 5 && !flags[2])
  {
    flags[2]++;
  }
  else if(DifB > 10 && flags[2])
  {
    flags[2]--;
  }
  
    
 if (compas > 15 && compas <180) {
    giroderecha();
  }else if (compas <345 && compas > 180) {
    giroizquierda();
    
  }
  else {
   /* if((ultD > 50 && ultD <100) && (ultI > 50 && ultI < 100)){
      Serial.println("esta centrado");
      paro();
      delay(200);
    }else */
    
      if(ultD <=40 && ultI >= 60)
      {
        Serial.println("Esta de lado derecho");
        izquierda();
        delay(200);
        
      }
      else if(ultD >= 90 && ultI <= 55)
      {
      Serial.println("Esta de lado Izquierdo");
      derecha();
      delay(200);
      }
      else if(ultB >= 21 &&( ultD >= 50 && ultD <= 100 )&& (ultI >=50 && ultI <= 100))
      {
       Serial.println("El robot esta adelantado"); 
        atras();
        delay(200);
      }
      else{
        Serial.println("El robot esta en posiciòn"); 
        paro();
        delay(200);
    
    }
  }
  
}

void ReadCompassSensor(){
  //this code lets the arduino know you want to talk to the compass Sensor
  Wire.beginTransmission(compassAddress);
  Wire.write(0x44);
  Wire.endTransmission();

  //the code below requests 2 bytes of information and then combines them
  //to make a number 0-360 that it saves in the variable TestValue
  Wire.requestFrom(compassAddress, 2); 
   while(Wire.available() < 2);
   byte lowbyte = Wire.read();  
   byte highbyte = Wire.read();
   TestValue = word(highbyte, lowbyte); 
}
