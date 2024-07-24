#ifndef blink_h
#define blink_h

#include <Arduino.h>

static const int ledPin = LED_BUILTIN; // Chân D4 của ESP8266
static int dem = 0;
static int num = 0;
static unsigned int time1 = 0;

void setup_blink();
void blink(int dem);
void blink_milis();

#endif