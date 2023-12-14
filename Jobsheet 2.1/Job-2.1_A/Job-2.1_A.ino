// Job 2.1 A
// Adriano, Refal, Yulio

#include "WiFi.h"
void setup(){
 Serial.begin(115200);
 WiFi.mode(WIFI_MODE_STA);
 Serial.println(WiFi.macAddress());
}
void loop(){
}
