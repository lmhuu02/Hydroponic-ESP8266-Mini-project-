#include "wifi_firebase.h"

unsigned int count_time_wifi = 0;

void setup_wifi(){
    /*setup connect wifi and firebase*/
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      delay(200);
      count_time_wifi++;
      if(count_time_wifi > 500){
        break;
      }
    }
    if(count_time_wifi > 500){
        Serial.println("Time out - connecting False Wifi");
        Serial.println("plase reset module wifi ESP");
    }else{
      Serial.println();
      Serial.print("Connected Wifi with IP: ");
      Serial.println(WiFi.localIP());
      Serial.println();
    }
    digitalWrite(LED_BUILTIN, HIGH);
}

void setup_firebase(){
    /*setup firebase*/
    // Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);

    /*set default data get to firebase: off*/
    Firebase.setString(firebaseData,"data/status","0");
    Firebase.setInt(firebaseData,"data/time",0);
}