/ controller nodemcu code

#include <SoftwareSerial.h> 
#define TX D6 // arduino softSerial RX -> NodeMcu D6(TX)
#define RX D7 // arduino softSerial TX -> NodeMcu D7(RX) 
SoftwareSerial arduSerial(RX, TX); // (RX, TX)

void setup() {
  Serial.begin(9600);
  arduSerial.begin(9600);
}

void loop() {
  if (arduSerial.available() > 0) {
    uint8_t temp = arduSerial.read();
    Serial.print(temp,HEX);
  }
  else {
    Serial.println();
    arduSerial.write(0);
    delay(1000);  // 응답 대기 시간
  }
}
