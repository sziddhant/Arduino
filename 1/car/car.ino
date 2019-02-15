#define trigPin 9
#define echoPin 12
#define led 10
#define led2 11
#define led3 13
#define pb 2
#define b 8
int z=0;
int q=0;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(pb,INPUT);
  pinMode(b,INPUT);
}

void loop() {
 z=digitalRead(pb) ;
  if(z==HIGH){
  
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(1); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(1); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 22) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 2000 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  
  delay(100);
}
else{
  digitalWrite(led3,HIGH);
  digitalWrite(led,LOW);
  digitalWrite(led2,LOW);
delay(100);
}
q=digitalRead(8);
if(b==HIGH)
{  digitalWrite(led3,HIGH);
  digitalWrite(led,HIGH);
  digitalWrite(led2,HIGH);
}
}
