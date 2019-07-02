#include <Ultra.h>







Ultra ULTI(49,47);
Ultra ULTB(48,46);
Ultra ULTD(41,39);

void setup() {
  
  Serial.begin(9600);
  
   
}

void loop() {
Serial.print(ULTD.getDistance());
Serial.print(" ");
Serial.print(ULTI.getDistance());
Serial.print(" ");
Serial.print(ULTB.getDistance());
Serial.println(" ");
delay(100);
}
