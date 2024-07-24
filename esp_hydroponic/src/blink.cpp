#include "blink.h"

void setup_blink(){
    pinMode(ledPin, OUTPUT); // Thiết lập chân D4 là OUTPUT
    time1 =millis();
}

void blink(int dem){
    dem = dem +1;
    digitalWrite(LED_BUILTIN, LOW); 
    delay(270); 
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(70); 
    digitalWrite(LED_BUILTIN, LOW); // Bật đèn LED
    delay(175); 
    digitalWrite(LED_BUILTIN, HIGH); // Tắt đèn LED
    delay(3500); 
    Serial.print("Chay lan thu: ");
    // Serial.println(dem);
}

void blink_milis(){
  if ((unsigned int)millis()-time1 >5000){
        if(num == 0){
            digitalWrite(LED_BUILTIN, LOW);
            Serial.println("bat led");
            num = 1;
        }else if(num == 1){
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.println("tat led");
            // delay(5000);
            num = 0;
        }

        time1 = millis();
        Serial.print(" time: ");
        Serial.println(time1);
    }
}