#include <DHT.h>
#include <ESP8266WiFi.h>

#define errorPin 16
#define DHTPIN D3
#define DHTTYPE DHT22


DHT dht(DHTPIN, DHTTYPE);


const int sleep_time = 20;  
WiFiClient client;




const char* ssid = "ssid";
const char* password = "pass";

void setup()
{
  pinMode(errorPin, OUTPUT); 
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(errorPin , HIGH);
    delay(200);
    digitalWrite(errorPin , LOW);
    delay(200);
  }

  
  Serial.begin(115200);

  dht.begin();

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  
  int n = WiFi.scanNetworks();

  Serial.println("scan done");
  if (n == 0)
  {
    Serial.println("no networks found");
    Serial.println("Going into sleep");
  }

  WiFi.begin(ssid, password);

  Serial.println("");
  Serial.println("Wi-Fi connected");
}
float temp;
float hum;


char server[] = {"192.168.124.153"};
int port = 1880;

unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 10L * 1000L;

void transmitSensorData()
{
  while (client.available()) 
  {
    char c = client.read();
    Serial.write(c);
  }

  if (millis() - lastConnectionTime > postingInterval) 
  {
    client.stop();
    
    String requestData = "requestVar=" + String(hum);
    
    Serial.println("[INFO] Connecting to Server");   
        
    if (client.connect(server, port)) 
    {
      Serial.println("[INFO] Server Connected - HTTP GET Started");
       
      client.println("GET /tweetumidade?" + requestData + " HTTP/1.1");
      client.println("Host: " + String(server));
      client.println("Connection: close");
      client.println();    

      lastConnectionTime = millis();
    
      Serial.println("[INFO] HTTP GET Completed");
    } 
    else 
    {
      // Connection to server:port failed
      Serial.println("[ERROR] Connection Failed");
    }    
  }

  Serial.println("-----------------------------------------------");  
}

void loop()
{
  
  temp = dht.readTemperature(); //true retorna valor em celsius
  hum = dht.readHumidity();

  delay(sleep_time * 1000);

  transmitSensorData();  

  delay(6000); 
}
