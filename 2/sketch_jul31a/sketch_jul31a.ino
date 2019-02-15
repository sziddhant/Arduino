#include <Servo.h>
#define b 2
#define bb 8
int z=0;
int q=0;
Servo myservo;
int servoPin = 3;
int off = 0;
int on = 80;

void setup() {
    Serial.begin(9600);
  myservo.attach(servoPin);
  myservo.write(on);
    pinMode(bb,INPUT);
  pinMode(b,INPUT);
}

void loop() {

z = digitalRead(b);
if (z== HIGH){
  myservo.write(on);
}else { myservo.write(off);
  }
delay(100);

}

