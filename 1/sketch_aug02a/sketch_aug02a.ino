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

  
 
  digitalWrite(rr,LOW); 
  digitalWrite(rl,LOW);
  digitalWrite(right,LOW);
  digitalWrite(left,LOW);


     digitalWrite(right,HIGH);
    digitalWrite(left,HIGH);
      digitalWrite(rr,LOW);
  digitalWrite(rl,LOW);
  
    
  

  delay(100);
  }





