#include "GY_85.h"
#include <Wire.h>

GY_85 GY85;
double a = 0;
double cx, cy;
int n=100;// no of readings to average
double initial_cx=0, initial_cy=0;
void setup()
{
  Wire.begin();
  delay(10);
  Serial.begin(9600);
  delay(10);
  GY85.init();
  delay(10);
Serial.println("Intitializing..");
  for (int z = 0; z < 100; z++) {
    initial_cx += GY85.compass_x( GY85.readFromCompass() );
    delay(10);
  }
  for (int z = 0; z < 100; z++) {
    initial_cy = GY85.compass_y( GY85.readFromCompass() );
    delay(10);
  }
  initial_cx = initial_cx / 1000;
  initial_cy = initial_cy / 1000;
}


void loop()
{
  for (int x = 0; x < n; x++)
  {
    cx = cx +( GY85.compass_x( GY85.readFromCompass() )/n);
    //delay(10);
  }
  for (int x = 0; x < n; x++)
  {
    cy = cy + (GY85.compass_y( GY85.readFromCompass() )/n);
    //delay(10);
  }

  cx = initial_cx - cx;
  cy = initial_cy - cy;

  a = atan2(cx, cy);
  a = a * (180 / PI);
  a=180-a;
 
  Serial.println  (a);
  cx = 0;
  cy = 0;
  delay(10);             // only read every 0,5 seconds, 10ms for 100Hz, 20ms for 50Hz
}
