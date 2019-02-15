#define trigPin 9
#define echoPin 12
#define left 10
#define right 3
#define rr 5
#define rl 6

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
     Serial.print(distance);
    Serial.println(" cm STOPPED");
    
  
  digitalWrite(rr,HIGH);
    digitalWrite(rl,HIGH);
      digitalWrite(right,LOW);
  digitalWrite(left,LOW);
  delay(100);
    
    
      digitalWrite(left,LOW);
    digitalWrite(rr,LOW); 
  digitalWrite(rl,HIGH);
  digitalWrite(right,HIGH);

}



if (distance < 50 && distance > 30)
{ 
  analogWrite(left,20);
    analogWrite(rr,0); 
  analogWrite(rl,0);
  analogWrite(right,20);
    Serial.println("Speed 20");
delay(100);}




if (distance < 60 && distance > 50)
{ 
  analogWrite(left,75);
    analogWrite(rr,0); 
  analogWrite(rl,0);
  analogWrite(right,75);
    Serial.println("Speed 75");
delay(100);}





if (distance < 80 && distance > 70)
{ 
  analogWrite(left,150);
    analogWrite(rr,0); 
  analogWrite(rl,0);
  analogWrite(right,150);
  
    Serial.println("Speed 150");
delay(100);}




  else {
    
 
    
    Serial.print(distance);
    Serial.println(" cm");
     digitalWrite(right,HIGH);
    digitalWrite(left,HIGH);
      digitalWrite(rr,LOW);
  digitalWrite(rl,LOW);
    Serial.println("Speed Digital");
  
    
  }

  delay(100);
  
}


