#ifndef DHT11_LCD_H
#define DHT11_LCD_H

#include "main.h"
#include <DHT.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4 //D2
// #define DHTPIN D1
#define DHTTYPE DHT11 //DHT 11

void test_dht(DHT dht);

void setup_dht(DHT dht);
void serial_dht(DHT dht);

void setup_lcd(LiquidCrystal_I2C lcd);
void show_data_dht11_lcd(DHT dht, LiquidCrystal_I2C lcd);

#endif 