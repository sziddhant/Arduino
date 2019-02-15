#include <SoftwareSerial.h>
SoftwareSerial esp(10,11); //ESP firmware has to be 0018000902 so the baudrate can be set to 9600
String str; //serial input&output
String stresp; //ESP input& output

void setup()
{
Serial.begin(9600);
esp.begin(9600);
}

void loop()
{
Serial.println("unesi komandu/fire the AT command"); 
delay(100);
while(Serial.available() == 0){}
str=Serial.readString();
esp.println(str);
while(esp.available() == 0){}
stresp=esp.readString();
Serial.println(stresp);
}

