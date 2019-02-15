#include<StackArray.h>

#define cut 650
#define maxNodes 200
#define motorSpeed 110

#define NUM_SENSORS             5  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             2  // emitter is controlled by digital pin 2

unsigned int sensorValues[NUM_SENSORS];
unsigned int threshold[5] = {638, 641, 743, 757, 683};
float Kp=18,Ki=0.02,Kd=160;
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;
int initial_motor_speed=100;

int absDir = 1;
int preDir = 1;
int curDir = 1;
int sensor[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int i = 0;

int dryPath[maxNodes];
int finalPath[maxNodes];
int finalPathLength = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);  //Motor Outputs
  pinMode(6, OUTPUT);  //Motor Outputs
  pinMode(5, OUTPUT);  //Motor Outputs
  pinMode(3, OUTPUT);  //Motor Outputs
  pinMode(8, INPUT);   //Extra Digital Sensor Input
}

void loop(){
  forward();
}

void readSensorValue() {

  sensorValues[4] = analogRead(A0);
  sensorValues[3] = analogRead(A1);
  sensorValues[2] = analogRead(A2);
  sensorValues[1] = analogRead(A3);
  sensorValues[0] = analogRead(A4);
  
  for (int i = 0; i < 5; i++)
  {
    sensorValues[i] = (sensorValues[i]  > 700);
    sensor[i] = sensorValues[i];
  }
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

    P = error;
    I = I + previous_I;
    D = error-previous_error;
    
    PID_value = (Kp*P) + (Ki*I) + (Kd*D);
    
    previous_I=I;
    previous_error=error;

    int left_motor_speed = initial_motor_speed-PID_value;
    int right_motor_speed = initial_motor_speed+PID_value;
    
    constrain(left_motor_speed,0,255);
    constrain(right_motor_speed,0,255);
  
    analogWrite(5,right_motor_speed);   //Left Motor Speed
    analogWrite(3,0);  //Right Motor Speed
    analogWrite(9,left_motor_speed); 
    analogWrite(6,0); 
}


//void halt() {
//  analogWrite(9, 0);
//  analogWrite(6, 0);
//  analogWrite(5, 0);
//  analogWrite(3, 0);
//}
//
//void rightTurn() {
//  while(!(sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 0)) {
//    readSensorValue();
//    analogWrite(9,100);  // Positive Polarity: Left Motor: More speed.
//    analogWrite(6,0);
//    analogWrite(5,0);
//    analogWrite(3,100);   // Negative Polarity: Right Motor: Less speed.
//  }
//}
//
//void leftTurn() {
//  while(!(sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 0)) {
//    readSensorValue();
//    analogWrite(9,0);
//    analogWrite(6,100);   // Negative Polarity: Left Motor: Less speed.
//    analogWrite(5,100);  // Positive Polarity: Right Motor: More speed.
//    analogWrite(3,0);
//  }
//}
//
//void aboutTurn() {
//  while(!(sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 0)) {
//    readSensorValue();
//    analogWrite(10,100);  // Positive Polarity: Left Motor: Equal speed: Rotating at same place.
//    analogWrite(11,0);
//    analogWrite(12,0);
//    analogWrite(13,100);  // Negative Polarity: Right Motor: Equal speed: Rotating at same place.
//  }
//}
//
//int relCurDirPref(int p, int d) {
//  if(d == 2) {
//    if(p == 2) {
//      return 2;
//    } else if (p == 4) {
//      return 2;
//    } else if (p == 1) {
//      return 3;
//    } else if (p == 3) {
//      return 1;
//    }
//  } else if(d == 1) {
//    if(p == 2) {
//      return 1;
//    } else if (p == 4) {
//      return 3;
//    } else if (p == 1) {
//      return 2;
//    } else if (p == 3) {
//      return 4;
//    }
//  } else if(d == 3) {
//    if(p == 2) {
//      return 3;
//    } else if (p == 4) {
//      return 1;
//    } else if (p == 1) {
//      return 4;
//    } else if (p == 3) {
//      return 2;
//    }
//  } else if(d == 4) {
//    if(p == 2) {
//      return 4;
//    } else if (p == 4) {
//      return 4;
//    } else if (p == 1) {
//      return 1;
//    } else if (p == 3) {
//      return 3;
//    }
//  }
//}
//
//int absDirPref(int preDir, int curDir) {
//  if (preDir == 1)
//    return curDir;
//  else if (preDir == 2) {
//    if (curDir == 1)
//      return 1;
//    else if (curDir == 2)
//      return 4;
//    else if (curDir == 3)
//      return 2;
//    else if (curDir == 4)
//      return 3;
//  } else if (preDir == 3) {
//    if (curDir == 1)
//      return 3;
//    else if (curDir == 2)
//      return 2;
//    else if (curDir == 3)
//      return 4;
//    else if (curDir == 4)
//      return 1;
//  } else if (preDir == 4) {
//    if (curDir == 1)
//      return 2;
//    else if (curDir == 2)
//      return 3;
//    else if (curDir == 3)
//      return 1;
//    else if (curDir == 4)
//      return 4;
//  }
//}
//
//void finalRun(){
//  preDir = 2;
//  for(int index = 0; index < finalPathLength; index++) {
//    curDir = relCurDirPref(preDir, finalPath[index]);
//    preDir = curDir;
//    if (curDir == 1)
//      rightTurn();
//    else if (curDir == 3)
//      leftTurn();
//    else if (curDir == 4)
//      aboutTurn();
//    readSensorValue();
//    while (sensor[6] == 0 && sensor[7] == 0)
//      forward();
//  }
//  while(1)
//    digitalWrite(53, HIGH);
//}
//
//void explorePath() {
//  StackArray<int> finalStack;
//  finalStack.push(dryPath[0]);
//  for(int index = 1; index <= i; index++) {
//    int top = finalStack.pop();
//    if(dryPath[index] + top == 0)
//      continue;
//    else {
//      finalStack.push(top);
//      finalStack.push(dryPath[index]);
//    }
//  }
//  finalPathLength = finalStack.count();
//  for(int index = finalPathLength - 1; index >= 0; index--)
//    finalPath[index] = finalStack.pop();
//}
//
//void dryRun(){
//  while(1) {
//    readSensorValue();
//    while (sensor[6] == 0 && sensor[7] == 0)
//      forward();
//    if (sensor[0] == 1 && sensor[2] == 1 && sensor[4] == 1 && sensor[5] == 1 && sensor[6] == 1 && sensor[7] == 1) {
//      int t1 = millis();
//      int t2 = t1;
//      while((t2 - t1) < 500) {
//        forward();
//        t2 = millis();
//      }
//      if (sensor[0] == 1 && sensor[2] == 1 && sensor[4] == 1 && sensor[5] == 1 && sensor[6] == 1 && sensor[7] == 1) {
//        halt();
//        break;
//      }
//    }
//    
//    if (sensor[7] == 1){
//      curDir = 1;
//      rightTurn();
//    } else if (sensor[2] == 1 || sensor[1] == 1 || sensor[3] == 1) {
//      curDir = 2;
//    } else if (sensor[6] == 1) {
//      curDir = 3;
//      leftTurn();
//    } else if (sensor[2] == 0) {
//      curDir = 4;
//      aboutTurn();
//    }
//      
//    preDir = absDir;
//    absDir = absDirPref(preDir, curDir);
//    if (absDir == 1) {
//      dryPath[i] = 1;
//      i++;
//    } else if (absDir == 2) {
//      dryPath[i] = 2;
//      i++;
//    } else if (absDir == 3) {
//      dryPath[i] = -1;
//      i++;
//    } else if (absDir == 4) {
//      dryPath[i] = -2;
//      i++;
//    }
//  }
//
//  digitalWrite(53, HIGH);
//  explorePath();
//  while(digitalRead(43))
//    digitalWrite(53, HIGH);
//  digitalWrite(53, LOW);
//}
