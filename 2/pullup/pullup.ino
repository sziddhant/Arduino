void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2,INPUT_PULLUP);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int v=digitalRead(2);
Serial.println(v);
if(v==HIGH){
  digitalWrite(13,HIGH);
}
else
{
  digitalWrite(13,LOW);}}
