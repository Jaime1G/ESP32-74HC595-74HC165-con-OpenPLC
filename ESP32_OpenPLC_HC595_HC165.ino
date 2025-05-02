#include <ShiftRegister74HC595.h>
#include <HC165.h>

ShiftRegister74HC595<1> sr(12, 22, 23);
HC165 sr165(15, 2, 0);

void sketch_setup()
{
  sr165.begin();
}

void sketch_loop()
{
  int DO0 = 0;
  sr.set(DO0, RELE_0);
  int DO1 = 1;
  sr.set(DO1, RELE_1);
  int DO2 = 2;
  sr.set(DO2, RELE_2);
  int DO3 = 3;
  sr.set(DO3, RELE_3);
  int DO4 = 4;
  sr.set(DO4, RELE_4);
  int DO5 = 5;
  sr.set(DO5, RELE_5);
  int DO6 = 6;
  sr.set(DO6, RELE_6);
  int DO7 = 7;
  sr.set(DO7, RELE_7);

  uint8_t inputVal = sr165.read();

  INT_1 = !((inputVal >> 0) & 1);
  INT_2 = !((inputVal >> 1) & 1);
  INT_3 = !((inputVal >> 2) & 1);
  INT_4 = !((inputVal >> 3) & 1);
  INT_5 = !((inputVal >> 4) & 1);
  INT_6 = !((inputVal >> 5) & 1);
  INT_7 = !((inputVal >> 6) & 1);
  INT_8 = !((inputVal >> 7) & 1);
}

