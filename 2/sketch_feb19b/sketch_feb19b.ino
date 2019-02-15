#include <Servo.h>
 
Servo myservo;
int servoPin = 9;
int unlock = 0;
int lock = 180;
 
void setup() {
 
Serial.begin(9600);
  myservo.attach(servoPin);
  myservo.write(lock);
}

void loop() {
  
   while (Serial.available()) {
    char inChar = (char)Serial.read();
    if(inChar == 'L'){
     if (myservo.read() <= 90) {
       Serial.println("Locked");
       Serial.println(myservo.read());
      myservo.attach(servoPin);
      
      
       myservo.write(lock);
        Serial.println(myservo.read());
       delay(3000);
        myservo.detach();
     }
     else {
      myservo.attach(servoPin);
       Serial.println("Open");
       myservo.write(unlock);
        Serial.println(myservo.read());
       delay(3000);
     myservo.detach();
     }
     
    }
  }  
}

