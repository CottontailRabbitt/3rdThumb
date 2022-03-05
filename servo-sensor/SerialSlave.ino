// sensor arduino code

#include <SoftwareSerial.h> 
#define TX 3 // nodeMcu softSerial RX -> arduino 3
#define RX 2 // nodeMcu softSerial TX -> arduino 2 
SoftwareSerial nodeSerial(RX, TX); // (RX, TX)

#define ledPin 13

float val = 12.54;

void setup() {
  Serial.begin(9600);
  nodeSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (nodeSerial.available() > 0) {
    uint8_t dump = nodeSerial.read();
    digitalWrite(ledPin, HIGH);
    nodeSerial.print(val);
  }
  else {
    Serial.println(val);
    delay(500);                // LED 표시 시간
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}