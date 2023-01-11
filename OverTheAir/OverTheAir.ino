#include <AsyncElegantOTA.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>

const char *ssid = "*****";
const char *password = "******";

AsyncWebServer server(80);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("WiFi Connection Attempt");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(400);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to WiFi Network with Name: ");
  Serial.print(ssid);
  Serial.print("IP Address for ESP32: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/plain", "OTA v2.0 - Update wirelessly"); });

  AsyncElegantOTA.begin(&server);
  server.begin();
  Serial.println("Elegant OTA Initiated");
  Serial.println("HTTP Server Has started Sucessfully");
  Serial.println("To access OTA Update, type");
  Serial.println(WiFi.localIP());
  Serial.println("/update");
}

void loop()
{
  // put your main code here, to run repeatedly:
}