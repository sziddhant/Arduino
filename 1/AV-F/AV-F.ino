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

  if ((distance < 40 && distance >10) || distance > 3411) {    //optional for error 3411
    // smooth turn if
     Serial.print(distance);
    Serial.println(" cm Caution!");
    
 

  
    //smooth right turn
      digitalWrite(left,LOW);
    digitalWrite(rr,LOW); 
  digitalWrite(rl,LOW);
  digitalWrite(right,HIGH);
delay(200);
 Serial.print("Turn done! ");
}

else if (distance < 10)  //less than 10 cm if

{

   Serial.print(distance);
    Serial.println(" STOP!");
     digitalWrite(right,LOW);
    digitalWrite(left,LOW);
      digitalWrite(rr,LOW);
  digitalWrite(rl,LOW);
  delay(100);       //stopping

   
    Serial.println("Rverse...");    //reverse
     digitalWrite(right,LOW);
    digitalWrite(left,LOW);
      digitalWrite(rr,HIGH);
  digitalWrite(rl,HIGH);
  delay(200);

  
}
else {
    
 
    
    Serial.print(distance);
    Serial.println(" cm no problem");
     digitalWrite(right,HIGH);
    digitalWrite(left,HIGH);
      digitalWrite(rr,LOW);
  digitalWrite(rl,LOW);
  
    
  

  delay(100);
  }


}


