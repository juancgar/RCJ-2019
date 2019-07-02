#include <Mux.h>


Mux a;
int Sig[10];

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  a.setSignatures(Sig);
  for(int i=0;i<=10;i++){
    Serial.print(Sig[i]);
    Serial.print(" ");
  }
  Serial.println();

}
