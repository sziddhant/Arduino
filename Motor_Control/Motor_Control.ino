volatile int count = 0;//if the interrupt will change this value, it must be volatile
int rpm=0;
unsigned long oldt=0;;
void setup() {
 pinMode(2, INPUT); //set as input
 digitalWrite(2, HIGH);
 digitalWrite(7, HIGH);
 attachInterrupt(digitalPinToInterrupt(2), interruptName, RISING);//Interrupt initialization
 Serial.begin(9600);
}//end setup

void loop() {
  if(count>=32)
  {
    rpm = ((count*60000)/(8*(millis()-oldt)));
    oldt=millis();
    count=0;
    Serial.println(rpm);
    
  }

 // delay(100);//Delays usually can't be interfered with, here we will see the interrupt work
}//end loop

void interruptName()
{
  count = count+1;
  //Serial.println(count);//see the counts advance
 // Serial.println("###");
}


