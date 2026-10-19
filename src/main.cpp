#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* nomeRedeWiFi = "SENAI EDUCACIONAL";
const char* senhaRedeWiFi = "info@134";
const String enderecoAPI = "https://wttr.in/Sao+Caetano+do+Sul?m&lang=pt&format=";

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(nomeRedeWiFi, senhaRedeWiFi);

  Serial.print("\n\r Iniciando conexão WiFi\n\r");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("#");
    delay(500);
  }

  Serial.printf("\n\rConectado com sucesso\n\r");
  Serial.printf("Endereco IP: %s\n\r", WiFi.localIP().toString().c_str());
  Serial.printf("Endereco MAC: %s\n\r", WiFi.macAddress().c_str());
}

void loop() {}

String pedirParaApiCLima(String codigo)
{
  HTTPClient http;
  http.begin(enderecoAPI + codigo);
  
  //? GET pra pegar o codigo http (404 - Not Found, 2XX - códigos de sucesso, etc.)
  int codigoHTTP = http.GET();
  String resposta;

  //? Se der sucesso
  if(codigoHTTP == 200)
  {
    resposta = http.getString();
  }
  else
  {
    Serial.printf("\n\rDeu erro. Código: %d", codigoHTTP);
  }
  http.end();
  return resposta;
}