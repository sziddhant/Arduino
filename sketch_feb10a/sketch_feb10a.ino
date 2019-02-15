#include <Keypad.h>


/* const char* ssid = "qwerty";
const char* password = "12345678";

#define HOSTIFTTT "maker.ifttt.com"
#define EVENTO "sms"
#define IFTTTKEY "dAKrxlkYxfIGtHRObCkhswhi6Zm8nlI0sFR-GrLtwm5"

WiFiClientSecure client;  */
 
const byte n_rows = 4;
const byte n_cols = 4;
 
char keys[n_rows][n_cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte colPins[n_cols] = {D4, D5, D6, D7};
byte rowPins[n_rows] = {D0, D1, D2, D3};
 
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 

 long randnumber ;

////////////////////////////////////////
 
void setup(){
 
  randomSeed(analogRead(0));
  Serial.begin(115200);
   delay(200);
  // WiFi.begin(ssid, password);
   //erial.println("");
    //Serial.print("Waiting to connect to WiFi... ");
    // while (WiFi.status() != WL_CONNECTED) {
    //delay(500);
    Serial.print(".");
   
}

/////////////////////////////////////////////

 /* Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
*/
 
void loop(){
  char myKey = myKeypad.getKey();
  randnumber = random(1000,9999);
  if (myKey != NULL){
    Serial.print("Key pressed: ");
    Serial.println(myKey);
    // Serial.println(randnumber);
    
  }
}
