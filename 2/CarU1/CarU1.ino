#define trigPin 9
#define echoPin 12
#define left 6
#define right 7
#define rr 8
#define rl 5


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

  
  long duration, distance, distancee;
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

  if (distance < 40 || distance > 3411) {    //optional for error 3411
     Serial.print(distance);
    Serial.println(" cm STOPPED");
    
    digitalWrite(right,LOW);
    digitalWrite(left,LOW);
      digitalWrite(rr,LOW);
  digitalWrite(rl,LOW);
  
  delay(200);
  
  digitalWrite(rr,HIGH);
    digitalWrite(rl,HIGH);
      digitalWrite(right,LOW);
  digitalWrite(left,LOW);
  delay(200);
    
    
      digitalWrite(left,LOW);
    digitalWrite(rr,LOW); 
  digitalWrite(rl,HIGH);
  digitalWrite(right,HIGH);

}
  

else {
    
 
    
    Serial.print(distance);
    Serial.println(" cm");
     digitalWrite(right,HIGH);
    digitalWrite(left,HIGH);
      digitalWrite(rr,LOW);
  digitalWrite(rl,LOW);
  
    
  

  delay(100);
  }


}


