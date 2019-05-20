#ifndef _DFRobot_Display_Latch_H
#define _DFRobot_Display_Latch_H

#include "DFRobot_Display.h"

class DFRobot_ST7687S_Latch : public DFRobot_Display {

    public:
       DFRobot_ST7687S_Latch(uint8_t pin_cs, uint8_t pin_rs, uint8_t pin_wr, uint8_t pin_lck) :
       DFRobot_Display(pin_cs, pin_rs, pin_wr, pin_lck) {}
};

#endif


