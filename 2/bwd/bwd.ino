const int led=13;
int st=LOW;
long pr=0;
long i=1000;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long cr=millis();
if(cr-pr >i)
{
  pr=cr;

if(st==LOW)
st=HIGH;
else
st=LOW;
digitalWrite(led,st);
}
}
