#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHTesp.h>
#include <ArduinoJson.h>
 int temp_api = 1;
    float x=0;
const char* ssid = "DESKTOP-H0PEPGR 0022";
const char* password = "10298r*W";

int ledPin = D0; 
WiFiServer server(80);
DHTesp dht;

void setup() {
  Serial.begin(115200);
  delay(10);
 Serial.println("Status\tHumidity (%)\tTemperature (C)");
  String thisBoard= ARDUINO_BOARD;
  Serial.println(thisBoard);
   dht.setup(D6, DHTesp::DHT11);
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
//Check temperature and humidity
delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();


  
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
  if (request.indexOf("/API") != -1) {
         //Get temperature data from API
       // temp_api = -1;
      HTTPClient http;
      http.begin("https://api.openweathermap.org/data/2.5/weather?id=1268865&appid=79e0b7a14056fb04b7d0c3418926434d");
      int httpCode = http.GET();
       if (httpCode >0)
        {
          String payload = http.getString();
          Serial.println(payload); //print to serial
          
         }
         delay(1000);
      http.end();
      
      //parsing program (help from https://arduinojson.org/v5/assistant/)
      
     const size_t bufferSize = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 2*JSON_OBJECT_SIZE(2) + 2*JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(7) + JSON_OBJECT_SIZE(11) + 410;
DynamicJsonBuffer jsonBuffer(bufferSize);

const char* json = "{\"coord\":{\"lon\":73.03,\"lat\":26.29},\"weather\":[{\"id\":800,\"main\":\"Clear\",\"description\":\"clear sky\",\"icon\":\"01n\"}],\"base\":\"stations\",\"main\":{\"temp\":307.195,\"pressure\":986.68,\"humidity\":42,\"temp_min\":307.195,\"temp_max\":307.195,\"sea_level\":1014.07,\"grnd_level\":986.68},\"wind\":{\"speed\":3.92,\"deg\":239},\"clouds\":{\"all\":0},\"dt\":1536240443,\"sys\":{\"message\":0.0619,\"country\":\"IN\",\"sunrise\":1536194997,\"sunset\":1536240116},\"id\":1268865,\"name\":\"Jodhpur\",\"cod\":200}";

JsonObject& root = jsonBuffer.parseObject(json);

float coord_lon = root["coord"]["lon"]; // 73.03
float coord_lat = root["coord"]["lat"]; // 26.29

JsonObject& weather0 = root["weather"][0];
int weather0_id = weather0["id"]; // 800
const char* weather0_main = weather0["main"]; 
const char* weather0_description = weather0["description"]; 
const char* weather0_icon = weather0["icon"]; 

const char* base = root["base"]; // "stations"

JsonObject& main = root["main"];
float main_temp = main["temp"]; 
    //  float main_temp = main["temp"];
      x= (int)main_temp;
      Serial.println("#############");
      Serial.println("");
      Serial.println(x);
            Serial.println(main_temp);
      Serial.println("##############");
            Serial.println("");
                  Serial.println(json);
      Serial.println("##############");
        //  Serial.println(main["temp"]);
      
      delay(1000);

    
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
  client.println("<a href=\"/API\"\"><button>Jodhpur Temperature </button></a><br />");
    client.println("<br>");
  client.println("<a href=\"/\"\"><button>Refresh </button></a><br />"); 
  
  client.println("<br><br>");
  client.println("<br><br>");
  //print on webpage
  client.println("Temperature = ");
  client.print(temperature);  
  client.println("");
  client.println("Humidity = ");
  client.println(humidity);
  client.println("");
  client.println("");
  client.println("");
    client.println("</br>");
  client.println("Weather Underground");
  
    client.println("</br>");
  client.println("Temperature= ");
  float y= x-273;
  client.println(y);
  
  //print to serial
  Serial.print("Temperature = ");
  Serial.print(temperature);  
  Serial.println("");
  Serial.print("Humidity = ");
  Serial.println(humidity);  
// Tweet 
  client.println("<br><br>");
  client.println("");
  client.println("<a class=\"twitter-share-button\" href=\"https://twitter.com/intent/tweet?text=Hello%20world%20Sent%20from%20NodeMCU\"data-size=\"large\">Tweet</a>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}


 void api_call()
 {
 
 }

