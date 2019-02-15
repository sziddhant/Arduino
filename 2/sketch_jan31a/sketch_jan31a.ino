
const int openn=9;
const int closee=10;
const int con=12;
const int light=8;
const int conc=11;
  int swtch=0;
  int x=0;
  
  void setup() {

pinMode(openn,OUTPUT);
pinMode(closee,OUTPUT);
pinMode(con,INPUT);
pinMode(light,OUTPUT);
pinMode(conc,INPUT);
}


void loop() {

  swtch=digitalRead(con);
  if(swtch==HIGH){
    digitalWrite(openn,HIGH);
    delay(500);
   digitalWrite(openn,LOW);
  }
  x=digitalRead(conc);
if(x==HIGH){
   digitalWrite(closee,HIGH);

delay(500);
 digitalWrite(closee,LOW);
}
delay(1000);
}
