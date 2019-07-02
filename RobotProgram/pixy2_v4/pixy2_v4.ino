#include <Wire.h>

  
#include <Pixy2.h>

// This is the main Pixy object 
Pixy2 pixy;




const int muxSIG = A2;
const int muxS0 = 44;
const int muxS1 = 42;
const int muxS2 = 40;
const int muxS3 = 38;
 
void SetMuxChannel(int channel)
{
  unsigned int S0,S1,S2,S3, p;
  byte k;
  
   k = (byte)channel;

   
   S0 = k & B0000001;
   digitalWrite(44,S0);
   k = (k >>1);
   
   S1 = k & B0000001;
   digitalWrite(42,S1);
   k = (k >>1);
   
   S2 = k & B0000001;
   digitalWrite(40,S2);
   k = (k >>1);
   
   S3 = k & B0000001;
   digitalWrite(38,S3);
  
   
}



int at1;
int at2;
int at3;
int ad1;
int ad2;
int iz1;
int iz2;
int iz3;
int de1;
int de2;
int de3;



int AL1=10;
int AL2=8;
int AL3=9;//pwm
int BL1=13;
int BL2=11;
int BL3=12;//pwm
int CL1=7;
int CL2=5;
int CL3=6;//pwm
int DL1=22;
int DL2=24;
int DL3=3;//pwm





int alan;

int X=0;
int i;

int dos;
int compas;



int compassAddress = 0x01; //we got this from I2C Scanner
int TestValue;





void paro() {
  analogWrite(AL3, 100);
  digitalWrite(AL2, 0);
  digitalWrite(AL1, 0);
  analogWrite(BL3, 100);
  digitalWrite(BL2, 0);
  digitalWrite(BL1, 0);
  analogWrite(CL3, 100);
  digitalWrite(CL2, 0);
  digitalWrite(CL1, 0);
  analogWrite(DL3, 100);
  digitalWrite(DL2, 0);
  digitalWrite(DL1, 0);
}



void adelante() {
  analogWrite(AL3, 100);
  digitalWrite(AL2, 1);
  digitalWrite(AL1, 0);
  analogWrite(BL3, 100);
  digitalWrite(BL2, 1);
  digitalWrite(BL1, 0);
  analogWrite(CL3, 100);
  digitalWrite(CL2, 1);
  digitalWrite(CL1, 0);
  analogWrite(DL3, 100);
  digitalWrite(DL2, 1);
  digitalWrite(DL1, 0);
}

void atras() {
  analogWrite(AL3, 100);
  digitalWrite(AL2, 0);
  digitalWrite(AL1, 1);
  analogWrite(BL3, 100);
  digitalWrite(BL2, 0);
  digitalWrite(BL1, 1);
  analogWrite(CL3, 100);
  digitalWrite(CL2, 0);
  digitalWrite(CL1, 1);
  analogWrite(DL3, 100);
  digitalWrite(DL2, 0);
  digitalWrite(DL1, 1);
}


void izquierda() {
  analogWrite(AL3, 100);
  digitalWrite(AL2, 1);
  digitalWrite(AL1, 0);
  analogWrite(BL3, 100);
  digitalWrite(BL2, 0);
  digitalWrite(BL1, 1);
  analogWrite(CL3, 100);
  digitalWrite(CL2, 1);
  digitalWrite(CL1, 0);
  analogWrite(DL3, 100);
  digitalWrite(DL2, 0);
  digitalWrite(DL1, 1);
}

void derecha() {
  analogWrite(AL3, 100);
  digitalWrite(AL2, 0);
  digitalWrite(AL1, 1);
  analogWrite(BL3, 100);
  digitalWrite(BL2, 1);
  digitalWrite(BL1, 0);
  analogWrite(CL3, 100);
  digitalWrite(CL2, 0);
  digitalWrite(CL1, 1);
  analogWrite(DL3, 100);
  digitalWrite(DL2, 1);
  digitalWrite(DL1, 0);
}


void giroderecha() {
  analogWrite(AL3, 100);
  digitalWrite(AL2, 0);
  digitalWrite(AL1, 0);
  analogWrite(BL3, 100);
  digitalWrite(BL2, 1);
  digitalWrite(BL1, 0);
  analogWrite(CL3, 100);
  digitalWrite(CL2, 1);
  digitalWrite(CL1, 0);
  analogWrite(DL3, 100);
  digitalWrite(DL2, 0);
  digitalWrite(DL1, 0);
}

void giroizquierda() {
  analogWrite(AL3, 100);
  digitalWrite(AL2, 1);
  digitalWrite(AL1, 0);
  analogWrite(BL3, 100);
  digitalWrite(BL2, 0);
  digitalWrite(BL1, 0);
  analogWrite(CL3, 100);
  digitalWrite(CL2, 0);
  digitalWrite(CL1, 0);
  analogWrite(DL3, 100);
  digitalWrite(DL2, 1);
  digitalWrite(DL1, 0);
}



  
void setup() {
 

  Serial.begin(115200);
  pixy.init();



   Wire.begin();  //turn on i2c
  Wire.beginTransmission(compassAddress); //open communication to sensor 
  Wire.write(0x00); //blank packetbm
  Wire.endTransmission(); //close communication
  while(Wire.available() > 0)
     Wire.read();


  pinMode(AL1, OUTPUT);
  pinMode(AL2, OUTPUT);
  pinMode(AL3, OUTPUT);
   pinMode(BL1, OUTPUT);
  pinMode(BL2, OUTPUT);
  pinMode(BL3, OUTPUT);
    pinMode(CL1, OUTPUT);
  pinMode(CL2, OUTPUT);
  pinMode(CL3, OUTPUT);
   pinMode(DL1, OUTPUT);
  pinMode(DL2, OUTPUT);
  pinMode(DL3, OUTPUT);


   pinMode(muxS0, OUTPUT);
   pinMode(muxS1, OUTPUT);
   pinMode(muxS2, OUTPUT);
   pinMode(muxS3, OUTPUT);

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


SetMuxChannel(10);
  at1 = analogRead(A2);
  SetMuxChannel(9);
  at2 = analogRead(A2);
  SetMuxChannel(8);
  at3 = analogRead(A2);


  SetMuxChannel(6);
  ad1 = analogRead(A2);
  SetMuxChannel(7);
  ad2 = analogRead(A2);


  SetMuxChannel(5);
  iz1 = analogRead(A2);
  SetMuxChannel(4);
  iz2 = analogRead(A2);
  SetMuxChannel(3);
  iz3 = analogRead(A2);


  SetMuxChannel(2);
  de1 = analogRead(A2);
  SetMuxChannel(1);
  de2 = analogRead(A2);
  SetMuxChannel(0);
  de3 = analogRead(A2);



    int i; 
  pixy.ccc.getBlocks();
   if (pixy.ccc.numBlocks){
    X = pixy.ccc.blocks[i].m_x;
   
   }
   else {
    X=0;
   }


Serial.println(X);


  if (compas > 25 && compas <180) {
    giroderecha();
  }else if (compas <335 && compas > 180) {
    giroizquierda();
    
  }
  else {

    if (at1 > 1000 || at2 > 1000 || at3 > 1000) {
      adelante();
    
      delay(500);
    }
    else if (ad1 > 1000 || ad2 > 1000 ) {
      atras();
      
      delay(500);
    }
    else if (iz1 > 1000 || iz2 > 1000 || iz3 > 1000) {
      derecha();
     
      delay(500);
    }
    else if (de1 > 1000 || de2 > 1000 || de3 > 1000) {
      izquierda();
   
      delay(500);
    }
    else {
  
  if (X >= 150 && X < 180) {
      adelante();

     }
     else if (X >0 && X <150) {
      izquierda();
   
     }
     else if (X > 180) {
      derecha();
     
     }
     else {
      atras();
   
     }
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
