#include <SPI.h>
#include "RF24.h"

RF24 radio(7,8);

byte address[6] = "1test";



void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(1,address);
  radio.startListening();
}

void loop() {

  unsigned long counter = 0;
  
  if (radio.available()) {
    radio.read(&counter, sizeof(unsigned long));
    Serial.print("Read: ");
    Serial.println(counter);
  }
}
