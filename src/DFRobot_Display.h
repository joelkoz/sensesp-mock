#ifndef _DFRobot_Display_H
#define _DFRobot_Display_H

#include "Arduino.h"

#define DISPLAY_BLACK 0
#define DISPLAY_WHITE 0xff

class DFRobot_Display {

    public:
        DFRobot_Display(uint8_t pin_cs, uint8_t pin_rs, uint8_t pin_wr, uint8_t pin_lck) {
        }

        void begin() {}

        void fillScreen(int color) {}
        void setTextColor(int color) {}
        void setTextBackground(int color) {}
        void setCursor(int x, int y) {}
        void setTextSize(int size) {}
        void printf(const char* str, ...) {}
        void drawLine(int x1, int y1, int x2, int y2, int color) {}
        void drawBmp(uint8_t* bmp, int x, int y, int w, int h) {}
        void fillCircle(int x, int y, int rad, int color) {}
        void fillRect(int x1, int y1, int x2, int y2, int color) {}

};

#endif