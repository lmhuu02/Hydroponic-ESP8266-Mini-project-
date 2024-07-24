#ifndef PUMP_H
#define PUMP_H

#include "main.h"

/*define control water pump*/
// #define enB D10
// #define enA D9
// #define in1 D5
// #define in2 D6
// #define in3 D7
// #define in4 D8

 const int enB = 3;
 const int enA = 1;
 const int in1 = 14;
const int in2 = 12;
const int in3 = 13;
const int in4 = 15;

static int num_pump = 0;
static unsigned int time_pump1 = 0;
static unsigned int time_pump2 = 0;

// int in1 = 14;
// int in2 = 12;
// int in3 = 13;
// int in4 = 15;
// int enA = 3;
// int enB = 1;

void setup_pump();
void control_pump_main(unsigned long time);
void control_pump_1();
void test_l298();

void milis_bom();

#endif