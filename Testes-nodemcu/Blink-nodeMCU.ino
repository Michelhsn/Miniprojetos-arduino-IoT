/* Blink no LED com NodeMCU
feito para prática curso de arduino */

#include <ESP8266WiFi.h> 

const char* ssid = "SSID";
const char* password = "Senha";
 
int ledPin = D3; // Porta NodeMCU

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Conecta a rede wifi
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
  Serial.println("WiFi connectado");
 
  // Start the server
  server.begin();
  Serial.println("Server inicializado");
 
  // Print the IP address
  Serial.print("IP na rede do Node ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Se houver client conectado
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Aguarda envio de dados
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Ler a primeira linha da requisição
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
    // Liga o LED
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    // Desliga o LED
    digitalWrite(ledPin, LOW);
    value = LOW;
  }

 
  // resposta servidor
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("O LEd está: ");
 
  if(value == HIGH) {
    client.print("Ligado");
  } else {
    client.print("Desligado");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Ligar </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Desligar </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
