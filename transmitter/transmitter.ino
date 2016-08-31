#include <SPI.h>
#include "RF24.h"

RF24 radio(7,8);

byte addresses[][6] = {"1Node","2Node"};

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(addresses[1]);
}

unsigned long demo = 0;

void loop() {
  demo++;

  Serial.println("writing");
  radio.write(&demo, sizeof(unsigned long));

  delay(1000);
}
