int dtect=8;
int sense=A0;
int buzzpin=9;
void setup()
{
  pinMode(dtect,OUTPUT);
  pinMode(sense,INPUT);
  pinMode(buzzpin,OUTPUT);
  digitalWrite(dtect,HIGH);
  Serial.begin(9600);
}
void loop()
{
  int val=analogRead(sense);
  Serial.println(val);
  if(val>=1005)
  {
    buzz(50);
  }
  
  
}
void buzz(unsigned char time)
  {
    analogWrite(buzzpin,170);
    delay(time);
    analogWrite(buzzpin,0);
    delay(time);
  }
