int index[100][2],type[100],point[100],xplr[100];
int dir,td,cd,tx,ty,cx,cy;
int tpr=0;
int cut=900;
int s0=0,s1=0,s2=0,s3=0,s4=0;
void setup() {

pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);

pinMode(A6,OUTPUT);
pinMode(A7,OUTPUT);
pinMode(A8,OUTPUT);
pinMode(A9,OUTPUT);

pinMode(52,INPUT);
pinMode(53,INPUT);
Serial.begin(9600);
}


void loop() {
  s0=analogRead(A0)/cut;
  s1=analogRead(A1)/cut;
  s2=analogRead(A2)/cut;
  s3=analogRead(A3)/cut;
  s4=analogRead(A4)/cut;
  s5=analogRead(A5)/cut;
  
  if (tpr==0) {
    px = index[tpr][0]=0;
    py = index[tpr][1]=0;
    xplr[tpr]=1;
    type[tpr]=(s0+s2+s4+s5)-1;
    if(s4 == 1){
      pd = cd = dir = 1;
    } else if (s5 == 1) {
      pd = cd = dir = 2;
    } else if (s0 == 1) {
      pd = cd = dir = 3;
    } else {
      pd = cd = dir = 4;
    }
    tpr++;
  }
  while (s2 == 1 && s5 == 1) {
    analogWrite(A6,225);
    analogWrite(A7,0);
    analogWrite(A8,225);
    analogWrite(A9,0);
  }
  
}
