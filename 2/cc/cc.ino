#include <TrueRandom.h>


#define trigPin 9
#define echoPin 12
#define left 10
#define right 8
#define rr 7
#define rl 6
int ran;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
    pinMode(rl, OUTPUT);
  pinMode(rr, OUTPUT);


}

void loop() {

  
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(1); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(1); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  digitalWrite(rr,LOW); 
  digitalWrite(rl,LOW);
  digitalWrite(right,LOW);
  digitalWrite(left,LOW);

  if (distance < 40) { 
   ran=TrueRandom.random(2);
   Serial.print(ran);

 
    digitalWrite(right,LOW);
    digitalWrite(left,LOW);
      digitalWrite(rr,LOW);
  digitalWrite(rl,LOW);
  
  delay(200);
  ran=TrueRandom.random(3);

    
        if (ran=1){
      digitalWrite(left,LOW);
    digitalWrite(rr,LOW); 
  digitalWrite(rl,HIGH);
  digitalWrite(right,HIGH);
        }
           if (ran=0) {
      digitalWrite(right,LOW);
    digitalWrite(rl,LOW); 
  digitalWrite(rr,HIGH);
  digitalWrite(left,HIGH);
        }
}
  

  else {
    
 
    
    Serial.print(distance);
    Serial.println(" cm");
     digitalWrite(right,HIGH);
    digitalWrite(left,HIGH);
      digitalWrite(rr,LOW);
  digitalWrite(rl,LOW);
    
  }

  delay(100);
  
}


