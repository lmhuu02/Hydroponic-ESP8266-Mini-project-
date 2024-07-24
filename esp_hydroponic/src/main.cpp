#include <Arduino.h>
#include <Wire.h>
#include "main.h"
#include "blink.h"
#include "dht11_lcd.h"
#include "pump.h"

/* Change these values based on your calibration values */
int lowerThreshold = 420;
int upperThreshold = 520;
// Sensor pins
#define sensorPower D0
#define sensorPin A0
// Value for storing water level
int val = 0;

// #include "wifi_firebase.h"

/*khoi tao cho cam bien dht11*/
DHT dht (DHTPIN, DHTTYPE);
/*Khởi tạo địa chỉ lcd I2C*/
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  // pinMode(sensorPower, OUTPUT);
  // digitalWrite(sensorPower, LOW);

  /*------------SETUP PUMP-------------*/
  setup_pump();
  /*------------SETUP LED BLINK ----------*/
  setup_blink();

  // setup_wifi();
  setup_pump();
  setup_dht(dht);
  setup_lcd(lcd); 

  /*------------BEGIN - DE CUOI-------------*/ 
  Serial.begin(9600);
}

//This is a function used to get the reading
int readSensor() {
    digitalWrite(sensorPower, HIGH);
    delay(10);
    val = analogRead(sensorPin);
    digitalWrite(sensorPower, LOW);
    return val;
}

void cambienmucnuoc(int level){
   
    if (level == 0) {
        Serial.println("Water Level: Empty");
        // lcd.clear();
        // lcd.backlight();
        // lcd.begin(16,2);
        // lcd.backlight();
        // lcd.setCursor(0, 0);  // Đặt con trỏ về vị trí (0, 0)
        // // lcd.print("Water Level: Empty ");    
        // delay(500);
    }
    else if (level > 0 && level <= lowerThreshold) {
        Serial.print("Water Level: Low ");
        Serial.println(level);
    //     Serial.print("\\");
    //     lcd.clear();
    //     lcd.backlight();
    //     lcd.begin(16,2);
    //     lcd.backlight();
    //     lcd.setCursor(0, 0);  // Đặt con trỏ về vị trí (0, 0)
    //     lcd.print("Water Level: Low ");    
        delay(500);
    }
    // else if (level > lowerThreshold && level <= upperThreshold) {
    //     Serial.println("Water Level: Medium");
    //     lcd.clear();
    //     lcd.backlight();
    //     lcd.begin(16,2);
    //     lcd.backlight();
    //     lcd.setCursor(0, 0);  // Đặt con trỏ về vị trí (0, 0)
    //     lcd.print("Water Level: Medium");    
    //     delay(500);
    // }
    // else if (level > upperThreshold) {
    //     Serial.println("Water Level: High");
    //     lcd.clear();
    //     lcd.backlight();
    //     lcd.begin(16,2);
    //     lcd.backlight();
    //     lcd.setCursor(0, 0);  // Đặt con trỏ về vị trí (0, 0)
    //     lcd.print("Water Level: High");    
    //     delay(500);
    // }
    delay(1000);
}


void test1_l298(){
    Serial.println("MAY BOM DAY NE");
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    digitalWrite (in1, HIGH); 
    digitalWrite (in2, LOW);
    Serial.print("bat 1");
    delay(5000);
    digitalWrite (in1, LOW); 
    digitalWrite (in2, LOW);
    Serial.print("tat 1");
    delay(2000);
    
    digitalWrite (in3, LOW); 
    digitalWrite (in4, HIGH);
    Serial.print("bat 2");
    delay(90000);
    digitalWrite (in3, LOW); 
    digitalWrite (in4, LOW);
    Serial.print("tat 2");
    delay(5000);
}

void loop()
{
  // blink_milis();
  // milis_bom();

  // test_l298();
  show_data_dht11_lcd(dht, lcd);
  // serial_dht(dht);
  // test_dht(dht);
//   test_l298();
  control_pump_main(time1);
//   Serial.println("main ");
  int level = readSensor();
  cambienmucnuoc(level);

}
