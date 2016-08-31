#include <SPI.h>
#include "RF24.h"

RF24 radio(7,8);

byte addresses[][6] = {"1Node","2Node"};

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(1,addresses[1]);
  radio.startListening();
}

void loop() {
  unsigned long demo = 0;
  
  if (radio.available()) {
    Serial.println("available");
    radio.read(&demo, sizeof(unsigned long));
    Serial.println(demo);
  }
}
