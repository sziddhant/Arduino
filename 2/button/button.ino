const int w=13 ;
const int z=12 ;
const int y=11 ;
const int x=10 ;
const int b=2;
int bs=0;
int pbc=0;
int lbs=0;
void setup() {
  
  // put your setup code here, to run once:
pinMode(w,OUTPUT);
pinMode(x,OUTPUT);
pinMode(y,OUTPUT);
pinMode(z,OUTPUT);
pinMode(b,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:



delay(100);
bs =digitalRead(b);
if(bs !=lbs){
  if(bs==HIGH){
    pbc++;
    Serial.println("on");
    Serial.print("number of button pushes:");
    Serial.println(pbc);
  }
  else{
    Serial.println("off");
  }
  delay(20);
}
lbs-bs;
if(pbc %2==0){
  digitalWrite(w,HIGH);
  digitalWrite(x,HIGH);
  digitalWrite(y,HIGH);
  digitalWrite(z,HIGH);

}
  else
 { digitalWrite(w,LOW);
 digitalWrite(x,LOW);
 digitalWrite(y,LOW);
 digitalWrite(z,LOW);}}
 
