#include <Compass.h>

void setup() {
  Serial.begin(9600);
  compassBegin();

}

void loop() {
  Serial.println(getDirection());
}