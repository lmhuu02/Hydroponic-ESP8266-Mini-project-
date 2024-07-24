#include "dht11_lcd.h"

void setup_dht(DHT dht){
    dht.begin();
}

void test_dht(DHT HT){
     HT.begin();
    float humi;
    float tempC;
    float tempF;
    delay(3000);
    humi = HT.readHumidity();
    tempC = HT.readTemperature();
    tempF = HT.readTemperature(true);

    Serial.print("Humidity:");
    Serial.print(humi,0);
    Serial.print("%");
    Serial.print(" Temperature:");
    Serial.print(tempC,1);
    Serial.print("°C ~ ");
    Serial.print(tempF,1);
    Serial.println("°F");
}

void serial_dht(DHT dht){
    /*read data dht11*/
    float humidity = dht.readHumidity();   
    float temperature = dht.readTemperature();
    // delay(2000);
    // Kiểm tra nếu giá trị lỗi
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        // return;
    }

    // In giá trị nhiệt độ và độ ẩm ra Serial Monitor
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%  Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
    // delay(2000);
}

void setup_lcd(LiquidCrystal_I2C lcd){
    Wire.begin(D4,D3);
    lcd.init();
    lcd.clear();
    lcd.begin(16,2);  // Khởi tạo màn hình LCD
    lcd.backlight();  // Bật đèn nền cho màn hình
    lcd.setCursor(0, 0);  /*vi tri 0 hang 1*/
    lcd.print("HELLO WORLD!");  // In ra màn hình
    delay(1000);
    lcd.setCursor(0, 1);  /*vi tri 0 hang 2*/
    lcd.print("DHT11 : LCD16X2");
    delay(2000);
}

void show_data_dht11_lcd(DHT dht, LiquidCrystal_I2C lcd){
     /*read data dht11*/
     dht.begin();
    float humidity;
    float temperature;

    humidity = dht.readHumidity();   
    temperature = dht.readTemperature();
    // Kiểm tra nếu giá trị lỗi
    // if (isnan(humidity) || isnan(temperature)) {
    //     // Serial.println("Failed to read from DHT sensor!");
    //     // return;
    //     Serial.print("00");
    // }

    /*gan gia tri tam thoi cho nhiet do do am*/
    // humidity = 65;
    // temperature = 30;
    /*show data in lcd 16x2*/
    // lcd.clear();
    
    lcd.backlight();
    lcd.begin(16,2);
    lcd.backlight();
    lcd.setCursor(0, 0);  // Đặt con trỏ về vị trí (0, 0)
    lcd.print("Do am: ");
    lcd.setCursor(6, 0); /*dat vi tri 6 tren dong 1*/
    lcd.print(humidity);
    lcd.setCursor(10, 0);
    lcd.print(" %");
    lcd.setCursor(0, 1);  /*dat vi tri 0 tren dong 2*/
    lcd.print("Nhiet Do: ");
    lcd.setCursor(10, 1);  /*dat vi tri 10 tren dong 2*/
    lcd.print(temperature);
    lcd.setCursor(14, 1);
    lcd.print("°C");
    // delay(2000);
    lcd.backlight();
}
