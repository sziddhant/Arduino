#define trigPin 9
#define echoPin 12
#define led 10
#define led2 11
#define led3 13
#define pb 2
#define b 8
int z=0;
int q=0;
#include <Servo.h>
 
Servo myservo;
int servoPin = 3;
int unlock = 0;
int lock = 180;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(pb,INPUT);
  pinMode(b,INPUT);
  Serial.begin(9600);
  myservo.attach(servoPin);
  myservo.write(lock);
}

void loop() {
  
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(1); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(1); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  
  if (distance > 5) {  // This is where the LED On/Off happens
    Serial.print(distance);
    Serial.println(" cm");
  
   myservo.attach(servoPin);
       Serial.println("Locked");
       myservo.write(lock);
        Serial.println(myservo.read());
       delay(3000);
     myservo.detach();
}
  else {
    Serial.println("Open");
       Serial.println(myservo.read());
      myservo.attach(servoPin);
      
      
       myservo.write(unlock);
        Serial.println(myservo.read());
       delay(3000);
        myservo.detach();
  }
  if (distance >= 2000 || distance <= 0){
    Serial.println("Out of range");
  Serial.println("Locked");
       Serial.println(myservo.read());
      myservo.attach(servoPin);
      
      
       myservo.write(lock);
        Serial.println(myservo.read());
       delay(3000);
        myservo.detach();
  }
  
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  
  delay(100);

}
