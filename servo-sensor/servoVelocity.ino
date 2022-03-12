#include <Servo.h>    //서보모터 라이브러리 include
 
Servo microServo;    //서보모터 객체 선언
const int servoPin = 3;    //서보모터 제어핀 할당
 
void setup()
{
    Serial.begin(115200);
    Serial.println("hello arduino!");
    microServo.attach(servoPin);    //서보모터 초기화
}
 
void loop()
{
    int aValue = analogRead(A0);    //aValue 초기화, A0값을 aValue 변수에 저장
 
    aValue = map(aValue, 0, 1023, 0, 169);    //aValue의 스케일 변화, 0~1023 -> 0~169
 
    microServo.write(aValue);        //aValue 값으로 서보 모터 각도 제어
    Serial.println(aValue);
 
    delay(20);
}

