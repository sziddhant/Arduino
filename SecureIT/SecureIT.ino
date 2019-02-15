#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Keypad.h>
const char* ssid = "Vinod";
const char* password = "vinodwillsecureit";
int otp=0,otp_check=0,code=0,k=0;
int ledPin = D0; 
 int myKey=0;
WiFiServer server(80);
// Keypad code
const byte n_rows = 4;
const byte n_cols = 4;
 
char keys[n_rows][n_cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte colPins[n_cols] = {D4, D5, D6,D7};
byte rowPins[n_rows] = {D0, D1, D2, D3};
 
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 

 long randnumber ;

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  

  //Keypad check
   myKey = myKeypad.getKey();
  if (myKey!= NULL){
  for(int i=3;i<=0;i--){
    myKey = myKeypad.getKey();
  if (myKeypad.getKey() != NULL){
    Serial.print("Key pressed: ");
    Serial.println(myKeypad.getKey());
    k=int(myKey);
    code=code+k*pow(10,i);
    Serial.println(code);
   }}}

  
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait for the client to sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, LOW);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, HIGH);
    value = LOW;
  }
  if (request.indexOf("/OTP") != -1)  {
    randnumber = random(1000,9999);
  Serial.println(randnumber);
    otp= randnumber;
    otp_check=1;
  }

 
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
 
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");
    client.println("<br>");
client.println("<a href=\"/OTP\"\"><button>Generate OTP </button></a><br />");
    client.println("<br>");
  client.println("<a href=\"/\"\"><button>Refresh </button></a><br />"); 
  
  client.println("<br><br>");
  client.println("<br><br>");
  //print on webpage
  client.println("");
  if(otp_check!=0){
  client.println("OTP = ");
  client.println(otp);
  }
  
  client.println("");
  client.println("");
  client.println("</br>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");


  
 
}


 void api_call()
 {
 
 }

