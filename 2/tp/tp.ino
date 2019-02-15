const int a=11;
const int b=10;
const int c=9;
const int d=8;
const int z=2;
int t=0;
void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  t = digitalRead(z);
  if (t == HIGH){
  digitalWrite( a,HIGH);
  digitalWrite( b,HIGH);
  digitalWrite( c,HIGH);
  digitalWrite( d,HIGH);
}
 else{
    digitalWrite( a,LOW);
  digitalWrite( b,LOW);
  digitalWrite( c,LOW);
  digitalWrite( d,LOW);}
}
