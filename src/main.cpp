#include <Arduino.h>
#include <WiFi.h>

const char* nomeRedeWiFi = "SENAI EDUCACIONAL";
const char* senhaRedeWiFi = "info@134";

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

  Serial.printf("\n\rConectado com sucesso");
}

void loop() 
{
  
}