#include "analog_input.h"
#include "Arduino.h"
#include "ReactESP.h"

void AnalogInput::update() {
  output = 500;
  this->notify();
}

void AnalogInput::enable() {
  app.onRepeat(100, [this](){ this->update(); });
}
