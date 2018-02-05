// Este c�digo l� os dados do sensor DHT22 usando NodeMCU e os transmite para um servidor

#include <DHT_U.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#define errorPin 16
#define DHTPIN D3
#define DHTTYPE DHT22

// Atrav�s da biblioteca DHT, inicializa-se o objeto dht
DHT dht(DHTPIN, DHTTYPE);
const int sleep_time = 20;
//Inicia o client
WiFiClient client;
// Valores da rede wi-fi
const char* ssid = "SSID";
const char* password = "Senha";
// Fun��o Setup executada uma vez
void setup()
{
pinMode(errorPin, OUTPUT); // Apenas para indicar o Status
//da leitura dos dados.
// Inicializa a comunica��o serial com baud 115200.
Serial.begin(115200);
// In�cio da comunica��o com o sensor
dht.begin();
delay(10);
// Mensagens impressas para o usu�rio notar status da conex�o
S
WiFi.begin(ssid, password);
// Caso a conex�o tenha ocorrido com sucesso
Serial.println("");
Serial.println("Conectado ao Wi-Fi");
}
// Inicializa��o das vari�veis de temperatura e humidade
float temp;
float hum;
// Atribuindo-se os valores do ip do Server e a respectiva porta.
char server[] = {"localhost"};
int port = 80;
// Atribui��o de vari�veis para controle de intervalo na postagem dos dados
+ String(temp);
Serial.println("[INFO] Connecting to Server");
if (client.connect(server, port))
{
Serial.println("[INFO] Server Connected - HTTP GET Started");
// Requisi��o HTTP
client.println("GET /tempmonitor/add.php?" + requestData +

client.println("Host: " + String(server));
client.println("Connection: close");
client.println();
lastConnectionTime = millis();
Serial.println("[INFO] HTTP GET Completed");
}

