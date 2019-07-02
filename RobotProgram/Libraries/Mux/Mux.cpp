
#include "Mux.h"
Mux::Mux()
{
   pinMode(S0, OUTPUT);
   pinMode(S1, OUTPUT);
   pinMode(S2, OUTPUT);
   pinMode(S3, OUTPUT);
}
int Mux::setChannel(int Channel)
{
  unsigned int I0,I1,I2,I3;
  byte k;
  
   k = (byte)Channel;

   
   I0 = k & B0000001;
   digitalWrite(S0,I0);
   k = (k >>1);
   
   I1 = k & B0000001;
   digitalWrite(S1,I1);
   k = (k >>1);
   
   I2 = k & B0000001;
   digitalWrite(S2,I2);
   k = (k >>1);
   
   I3 = k & B0000001;
   digitalWrite(S3,I3);
   value = analogRead(SIG);

   //value = map(value,0,1023,0,255);
    return value;
}
void Mux::setSignatures(int arr[10])
{
  for(int i = 0; i <= 10; i++)
  {
    Signatures[10-i] =  setChannel(i);
    arr[10-i] = Signatures[10-i];
  }
}
