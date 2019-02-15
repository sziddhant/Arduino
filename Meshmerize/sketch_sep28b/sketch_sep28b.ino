int cut = 850;
float kp = 13.0;
int motorSpeed = 100;

float error = 0.0;

int sensor[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {  
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);  //Motor Outputs
  pinMode(9, OUTPUT);  //Motor Outputs
  pinMode(10, OUTPUT);  //Motor Outputs
  pinMode(11, OUTPUT);  //Motor Outputs
  
  
}
void loop() {
  // put your main code here, to run repeatedly:
forward();
}
void readSensorValue() {
  sensor[0] = analogRead(A0)/cut;
  sensor[1] = analogRead(A1)/cut;
  sensor[2] = analogRead(A2)/cut;
  sensor[3] = analogRead(A3)/cut;
  sensor[4] = analogRead(A4)/cut;
 // sensor[5] = analogRead(A5)/cut;
  
}


void forward() {
  readSensorValue();
  
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1))
    error=4;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1))
    error=3;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1))
    error=2;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0))
    error=1;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0))
    error=0;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))
    error=-1;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))
    error=-2;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
    error=-3;
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
    error=-4;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
    if(error==-4) 
      error=-5;
    else 
      error=5;
      
  analogWrite(8, (motorSpeed + (kp * error)));
  analogWrite(9, 0);
  analogWrite(10, (motorSpeed - (kp * error)));
  analogWrite(11, 0);
}
