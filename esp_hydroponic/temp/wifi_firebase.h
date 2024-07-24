#ifndef WIFI_FIREBASE_H
#define WIFI_FIREBASE_H

#include "main.h"
#include <ESP8266WiFi.h>
// #include <FirebaseEsp8266.h>
#include <Firebase.h>
#include <Firebase_ESP_Client.h>

#define WIFI_SSID "Live_9068."
#define WIFI_PASSWORD "256kb8bit1"

/*define firebase*/
#define FIREBASE_HOST "https://hydroponics-esp-default-rtdb.firebaseio.com/" 
#define FIREBASE_AUTH "gyLEvG9eM5_PptSDhjiYbpTW0ci6wxDC2TE4Vfpygc0"

//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;
FirebaseJson json;

void setup_wifi();
void setup_firebase();

#endif