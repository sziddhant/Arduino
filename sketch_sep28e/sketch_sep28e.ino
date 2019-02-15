void setup()
{ // put your setup code here, to run once:
Serial.begin(9600);
pinMode(8,INPUT);


}

void loop() {
  
  // put your main code here, to run repeatedly:
 Serial.println(analogRead(A0)/850);
 Serial.println(analogRead(A1)/850);
 Serial.println(analogRead(A2)/850);
 Serial.println(analogRead(A3)/850);
 Serial.println(analogRead(A4)/850);
 Serial.println(analogRead(A5)/850);
  Serial.println(digitalRead(8)); 
 //Serial.println(analogRead(A5)/850);
// Serial.println(digitalRead(10));
 
 //Serial.println(digitalRead(2));
Serial.println();
 delay(500);
}
