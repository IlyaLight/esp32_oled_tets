#ifndef DISPLAY_H_
#define DISPLAY_H_


#include "SSD1306Wire.h"
#define SDA_PIN 5
#define SLC_PIN 4
#define DISPLAY_WIDE  128
#define DISPLAY_HEIGHT  64

#define DEMO_DURATION 3000

extern SSD1306Wire display;

void setupDisplay();
void drawFontFaceDemo();
void drawTextFlowDemo();
void drawTextAlignmentDemo();
void drawRectDemo();
void drawCircleDemo();
void drawImageDemo();
void drawProgressBarDemo();
void demoLoop();

#endif