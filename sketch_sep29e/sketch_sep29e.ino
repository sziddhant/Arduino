void setup() {
  // put your setup code here, to run once:
 pinMode(3,OUTPUT); 
 pinMode(5,OUTPUT); 
 pinMode(6,OUTPUT); 
 pinMode(9,OUTPUT); 
}

void loop() {
  digitalWrite(5,HIGH);
  
  digitalWrite(3,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(6,LOW);
  // put your main code here, to run repeatedly:

}
