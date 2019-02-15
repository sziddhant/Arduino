const int l=11;
const int b=2;
int x=0;
int y=0;
int z=0;

void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
x=digitalRead(b);
if(x == HIGH)
{digitalWrite(l,HIGH);
}
if(y==LOW)
{digitalWrite(l,HIGH);}
  if(x==HIGH){
    digitalWrite(l,LOW);}
    delay(2000);
}

