#include "pump.h"

void setup_pump(){
    /*setup l298n contron pump*/
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    time_pump1 = millis();
    time_pump2 = millis();
}

void milis_bom(){
    int time_pump_on = 30000; //1p //360000; //bat 6 phut
    int time_pump_off = 60000; //2p //600000; //tat 10 phut
    int time_4minute = 240000;
    /*bat may bom trong 6 phut 1000x60x6*/
    if ((unsigned int)millis()-time_pump1 > time_pump_off){
        if(num_pump == 1){
            digitalWrite(LED_BUILTIN, LOW);
            Serial.println("tat bom");
            num_pump = 0;
            Serial.print(" time bom tat: ");
            Serial.println(time_pump2);    
        }
    }
    /*tat may bom trong 10 phut 1000x60x10*/
    if((unsigned int)millis()-time_pump2 > time_pump_on ){
        if(num_pump == 0){
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.println("bat bom");
            // delay(5000);
            num_pump = 1;
        }
        time_pump2 = millis();
        time_pump1 = millis();
        Serial.print(" time bom bat: ");
        Serial.println(time_pump2);
    }
}

void test_l298(){
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

void control_pump_main(unsigned long time){
    int num = 130; /*toc do may bom*/
    /*tinh thoi gian*/
    // unsigned long time =millis();

    // Serial.print("bom");

    /*chay may bom trong 6 phut*/
    // if((unsigned long) (millis() - time) > 10000){
        // Set Motor A may bom chinh: bat trong 6p
        analogWrite(enB, 130);
        analogWrite(enA, 245);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);   
        delay(400);         

        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(400);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        
        delay(20000);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        delay(30000);
        // Serial.println("bom nuoc");
    // }
    // /*tat may bom trong 15p*/
    // else if((unsigned long) (millis() - time) > 5000){
    //     // Set Motor A may bom chinh: tat trong 15p
    //     analogWrite(enB, 0);
    //     analogWrite(enA, 0);
    //     digitalWrite(in1, LOW);
    //     digitalWrite(in2, LOW);
    //     // cập nhật lại biến time
    //     time = millis();
    //     Serial.println("tat nuoc");
    // }
}

// void control_pump_1(){}
