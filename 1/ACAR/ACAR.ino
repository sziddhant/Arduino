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
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(5); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  digitalWrite(rr,LOW); 
  digitalWrite(rl,LOW);
  digitalWrite(right,LOW);
  digitalWrite(left,LOW);

  if (distance < 30 || distance > 3411) {    //for error 3411
     Serial.print(distance);
    Serial.println(" cm STOPPED");


    
    digitalWrite(right,LOW);
    digitalWrite(left,LOW);
    digitalWrite(rr,LOW);
    digitalWrite(rl,LOW);
  
 
  delay(500);

    
    //analysis beta
    

 digitalWrite(right,LOW);
    digitalWrite(left,LOW);
    digitalWrite(rr,LOW);
    digitalWrite(rl,LOW);
  delay(100);                    //stop

  Serial.println("Reverse...");
       digitalWrite(rr,LOW);
       digitalWrite(rl,HIGH);
        digitalWrite(right,HIGH);
       digitalWrite(left,LOW);
       delay(400);    
      //reverse..
  
       Serial.println("Left turn");
       digitalWrite(rr,LOW);
       digitalWrite(rl,HIGH);
        digitalWrite(right,HIGH);
       digitalWrite(left,LOW);
       delay(600);               //left



        digitalWrite(right,LOW);
    digitalWrite(left,LOW);
    digitalWrite(rr,LOW);
    digitalWrite(rl,LOW);
  delay(200);                    //stop
  

      //analyse left
      
       long durationL, distanceL, distanceeL;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(5); 
  digitalWrite(trigPin, LOW);
  durationL = pulseIn(echoPin, HIGH);
  distanceL = (durationL/2) / 29.1;
   Serial.print(distanceL);
    Serial.println(" cm Analysing");
  delay(100);
  

  //turn right
  Serial.println("Right turn");
       digitalWrite(rr,HIGH);
       digitalWrite(rl,LOW);
       digitalWrite(right,LOW);
       digitalWrite(left,HIGH);
       delay(1200);     

        digitalWrite(right,LOW);
    digitalWrite(left,LOW);
    digitalWrite(rr,LOW);
    digitalWrite(rl,LOW);
  delay(200);                    //stop



        //analyse right
      
       long durationR, distanceR, distanceeR;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(5); 
  digitalWrite(trigPin, LOW);
  durationR = pulseIn(echoPin, HIGH);
  distanceR = (durationR/2) / 29.1;
  delay(100);
  Serial.print(distanceR);
    Serial.println(" cm Analysing");
  delay(100);



// centering..
       Serial.println("centering..");
      digitalWrite(rr,LOW);
       digitalWrite(rl,HIGH);
        digitalWrite(right,HIGH);
       digitalWrite(left,LOW);
       delay(600);               



       
   digitalWrite(right,LOW);
    digitalWrite(left,LOW);
    digitalWrite(rr,LOW);
    digitalWrite(rl,LOW);
  delay(100);                    //stop


// mathamatical analysis


 if (distanceL > distanceR)
 {
  Serial.print("Turning left as there is more space which is ");
Serial.print(distanceL);
    Serial.println(" cm");

//turn left
 digitalWrite(rr,LOW);
       digitalWrite(rl,HIGH);
        digitalWrite(right,HIGH);
       digitalWrite(left,LOW);
       delay(200);               //left

  
 }

else if(distanceR>distanceL)

{
   Serial.print("Turning right as there is more space which is ");
Serial.print(distanceR);
    Serial.println(" cm");

//turn right

  digitalWrite(rr,HIGH);
       digitalWrite(rl,LOW);
       digitalWrite(right,LOW);
       digitalWrite(left,HIGH);
       delay(200); 
 
}


    
 

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


