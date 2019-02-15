#define BLYNK_PRINT DebugSerial
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX
#include <IRremote.h>
#include <MideaIR.h>
#define IR_EMITER 3
#define FIVE_SECONDS    5000
#include <BlynkSimpleStream.h>
char auth[] = "439f8147ba12498393bb5162b810c54d";

IRsend irsend;
MideaIR remote_control(&irsend);


void setup()
{
  // Debug console
  DebugSerial.begin(9600);

  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);



  pinMode(IR_EMITER, OUTPUT);
}

void loop()
{
  Blynk.run();
  if (digitalRead(7)==HIGH){
  if (digitalRead(13)==HIGH){
    remote_control.turnON();
   delay(FIVE_SECONDS);
  }
  if(digitalRead(11)==HIGH){

   remote_control.setTemperature(18);
  remote_control.emit();
  delay(10000);
  }
  digitalWrite(7,LOW);
}}

