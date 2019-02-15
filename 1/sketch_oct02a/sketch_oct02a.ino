#define trigPin 10
#define echoPin 12
#define led 11
#define led2 13

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
long duration, distance, d, du, z;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) /29.9792458;
duration = z;
delay(88); 
 digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  du = pulseIn(echoPin, HIGH);
  d = (du/2) /29.9792458;
  if (d < 11){
    d=(du+z)/0.1 ;
    
    Serial.print(d);
    Serial.println(" cm/s");
  }


}
