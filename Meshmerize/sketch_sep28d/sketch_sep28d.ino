float Kp=18,Ki=0.02,Kd=160;
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;
int sensor[5]={0, 0, 0, 0, 0};
int initial_motor_speed=100;
int cut=850;

void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

void setup()
{
 pinMode(3,OUTPUT); 
 pinMode(5,OUTPUT); 
 pinMode(6,OUTPUT); 
 pinMode(9,OUTPUT); 
 Serial.begin(9600); 
}

void loop()
{
    read_sensor_values();
    calculate_pid();
    motor_control();
     if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
  {
    analogWrite(3,0);   //Left Motor Speed
    analogWrite(5,0);  //Right Motor Speed
    analogWrite(6,0); 
    analogWrite(9,0);  
  };
}

void read_sensor_values()
{
 int i = 3; 
  sensor[0]=sensor[1]=sensor[2]=sensor[3]=sensor[4]=sensor[5]=sensor[6]=sensor[7]=0;
  while(i--){
    sensor[0] += analogRead(A0);
    sensor[1] += analogRead(A1);
    sensor[2] += analogRead(A2);
    sensor[3] += analogRead(A3);
    sensor[4] += analogRead(A4);
     
  }
  sensor[0]/=3*cut;sensor[1]/=3*cut;sensor[2]/=3*cut;sensor[3]/=3*cut;sensor[4]/=3*cut;sensor[5]/=3*cut;sensor[6]/=3*cut;sensor[7]/=3*cut;
 
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

}

void calculate_pid()
{
    P = error;
    I = I + previous_I;
    D = error-previous_error;
    
    PID_value = (Kp*P) + (Ki*I) + (Kd*D);
    
    previous_I=I;
    previous_error=error;
}

void motor_control()
{
    // Calculating the effective motor speed:
    int left_motor_speed = initial_motor_speed-PID_value;
    int right_motor_speed = initial_motor_speed+PID_value;
    
    // The motor speed should not exceed the max PWM value
    constrain(left_motor_speed,0,255);
    constrain(right_motor_speed,0,255);
  
  analogWrite(5,right_motor_speed);   //Left Motor Speed
    analogWrite(3,0);  //Right Motor Speed
    analogWrite(9,left_motor_speed); 
    analogWrite(6,0); 
    //following lines of code are to make the bot move forward
    /*The pin numbers and high, low values might be different
    depending on your connections */
 
}
