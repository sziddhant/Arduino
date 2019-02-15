int latchPin =5;
#define dataPin 4
#define clockPin 3

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
;
  Serial.begin(9600);
  while (! Serial); // Wait until Serial is ready - Leonardo
  Serial.println("Enter LED Number 0 to 7 or 'x' to clear");
}
void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '7')
    {
      int led = ch - '0';
   
     
      Serial.print("Turned on LED ");
      Serial.println(led);
    }
    if (ch == 'x')
    {
  

      Serial.println("Cleared");
    }
  }
}
