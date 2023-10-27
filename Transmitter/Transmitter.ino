#include <SPI.h>
#include <RF24Network.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
RF24Network network(radio);
const uint16_t this_node = 00;
const uint16_t node01 = 01;

void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);
}

void loop() {
  network.update();
  int text= random(1,5);
  RF24NetworkHeader header(node01);
  bool  ok = network.write(header, &text,sizeof(text));
  delay(1000);
}
