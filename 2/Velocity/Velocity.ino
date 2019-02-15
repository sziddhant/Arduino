#define trigPin 9
#define echoPin 12
#define left 10
#define right 8
#define rr 7
#define rl 6
int v;
int s;
int t;
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

  s=distance;
  delay(1000);
  
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(1); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(1); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  
  t=distance;
  v = (s-t);
  Serial.print(s);
  Serial.println("    ");
    Serial.print(t);
      Serial.println("    ");
      Serial.print(v);
      Serial.println("   m/s ");
  delay(1);
}
 
