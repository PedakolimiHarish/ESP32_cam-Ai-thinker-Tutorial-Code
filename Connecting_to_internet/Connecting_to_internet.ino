/**************************************************************
* A very simple example would be programming our board to capture from the internet the local time.
* This is a very good feature to have on hand on projects. The below code will do it for us:
**************************************************************/
#include <WiFi.h>
#include <NTPClient.h>

#include <WiFiUdp.h>

#define NTP_OFFSET  -3  * 60 * 60 // In seconds
#define NTP_INTERVAL 60 * 1000    // In miliseconds
#define NTP_ADDRESS  "google.com"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

void setup()
{
    Serial.begin(115200);
    timeClient.begin();
}
