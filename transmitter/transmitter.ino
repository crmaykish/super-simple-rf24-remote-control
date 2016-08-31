#include <SPI.h>
#include "RF24.h"

RF24 radio(7,8);

byte address[6] = "1test";

unsigned long counter = 0;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
}

void loop() {
  Serial.print("Sending: ");
  Serial.println(counter);
  radio.write(&counter, sizeof(unsigned long));

  counter++;

  delay(1000);
}
