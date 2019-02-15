#include <SimpleDHT.h>
#include <IRremote.h>
#include <MideaIR.h>
#define IR_EMITER 3
#define FIVE_SECONDS    5000

int pinDHT11 = 2;

SimpleDHT11 dht11;

IRsend irsend;
MideaIR remote_control(&irsend);

bool state = false;

void setup() {
  pinMode(IR_EMITER, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  byte temperature = 0;
  byte humidity = 0;

  int err = SimpleDHTErrSuccess;
  
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  delay(1500);
  
  if(temperature>23)
  {
     if (state == false)
    {
      remote_control.turnON();
      delay(FIVE_SECONDS);
      Serial.print("Initalizing");
      remote_control.setSpeedFan(fan_speed_3);
      remote_control.emit();
      delay(FIVE_SECONDS);
      remote_control.setTemperature(17);
      remote_control.emit();
      delay(FIVE_SECONDS);
      state= true;
    }
  }
  
  if (state == true){
    if(temperature ==23){
      remote_control.setTemperature(23);
      remote_control.emit();
      Serial.print("Set Temp 23");
      delay(FIVE_SECONDS);
 
    }

     else if(temperature >=20&& temperature<23){
      
      remote_control.setSpeedFan(fan_speed_1);
      remote_control.emit();
      delay(FIVE_SECONDS);
    
    }
    
    else if(temperature <20)
    {//ac OFF
    remote_control.turnOFF();
    Serial.print("Turning OFF AC"); 
    delay(FIVE_SECONDS);
    state= false;
 
     
      }
  }
  }
  

