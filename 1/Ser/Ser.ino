#include <Servo.h> 
 
Servo ser;  // create servo object to control a servo 
              
 
int i = 0;   
 
void setup() 
{ 
  ser.attach(9);  // attaches the servo on pin 9 to the servo object 
pinMode(12,INPUT);

} 
 
void loop() 
{ 
  i=digitalRead(12);
if(i ==HIGH)
ser.write(180);
else
ser.write(90);
} 
