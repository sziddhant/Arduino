
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int con = 0;
const int button = 3;  
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

pinMode(button,INPUT);
}
 
void loop() {

con = digitalRead(button);

if(con == LOW)
{ 
 pos= 180;
   myservo.attach(9);
    myservo.write(pos);
    
    delay(1000);
     myservo.detach();// waits 15ms for the servo to reach the position 
     } 

 else{
  
   pos= 0;
   myservo.attach(9);
    myservo.write(pos);
 
    delay(1500);
    myservo.detach(); 
  }                

  delay(100);
} 

