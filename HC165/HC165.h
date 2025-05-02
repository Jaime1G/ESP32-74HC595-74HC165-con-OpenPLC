#ifndef HC165_h
#define HC165_h

#include "Arduino.h"

class HC165 {
  public:
    // Constructor para inicializar pines
    HC165(int dataPin, int clockPin, int latchPin);

    // Inicializa los pines
    void begin();

    // Lee los 8 bits del 74HC165
    uint8_t read();

  private:
    int _dataPin;    // Pin para QH (serial input)
    int _clockPin;   // Pin para SH_CP (shift clock)
    int _latchPin;   // Pin para ST_CP (storage clock)
};

#endif

