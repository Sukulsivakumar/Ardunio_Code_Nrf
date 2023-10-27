#include <SPI.h>
#include <RF24Network.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN

RF24Network network(radio);
const uint16_t this_node = 01;


void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);
}

void loop() {
  network.update();
  while(network.available()){
    RF24NetworkHeader header;
    int k;
    network.read(header, &k,sizeof(k));
    Serial.println(k);
  }
  
}
