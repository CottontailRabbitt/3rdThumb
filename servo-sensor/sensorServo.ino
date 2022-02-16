#include <Servo.h>

Servo myservo;
int sensor = A2; //포트지정
int servo = 11;

void setup(){
    Serial.begin(9600);
    myservo.attach(servo);

}

void loop(){
    int val = analogRead(sensor);
    int angle = map(val,0,1023,0,180);
    Serial.println(angle);
    myservo.write(angle);
}
