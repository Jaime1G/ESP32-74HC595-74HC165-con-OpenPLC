//////////////////////////////// sketch section ////////////////////////////////

#include <ShiftRegister74HC595.h>
#include <HC165.h>  

// create a global shift register object
// parameters: <number of shift registers> (data pin, clock pin, latch pin)
ShiftRegister74HC595<1> sr(12, 22, 23);

// Crear un objeto HC165
HC165 sr165(15, 2, 0);

// Definir los pines HC165
const int dataPin = 15;    // QH (Salida serial) en el pin 15
const int clockPin = 2;    // SH_CP (Shift clock) en el pin 2
const int latchPin = 0;    // ST_CP (Storage clock) en el pin 0

void sketch_setup()
{
  sr165.begin();  // Inicializa el registro de desplazamiento del HC165
}


void sketch_loop()
{
  // Salidas de Reles de la placa ES32D26
  int DO0 = 0;
  sr.set(DO0, RELE_1);
  int DO1 = 1;
  sr.set(DO1, RELE_2);
  int DO2 = 2;
  sr.set(DO2, RELE_3);
  int DO3 = 3;
  sr.set(DO3, RELE_4);
  int DO4 = 4;
  sr.set(DO4, RELE_5);
  int DO5 = 5;
  sr.set(DO5, RELE_6);
  int DO6 = 6;
  sr.set(DO6, RELE_7);
  int DO7 = 7;
  sr.set(DO7, RELE_8);

  // === Leer entradas del HC165 ===
  uint8_t inputVal = sr165.read();  // Leer los 8 bits de las entradas del HC165

// Asignar los valores leídos a las variables de entrada INT_1 a INT_8, invirtiendo la lógica
  INT_1 = !((inputVal >> 0) & 1);  // Invertir el bit 0
  INT_2 = !((inputVal >> 1) & 1);  // Invertir el bit 1
  INT_3 = !((inputVal >> 2) & 1);  // Invertir el bit 2
  INT_4 = !((inputVal >> 3) & 1);  // Invertir el bit 3
  INT_5 = !((inputVal >> 4) & 1);  // Invertir el bit 4
  INT_6 = !((inputVal >> 5) & 1);  // Invertir el bit 5
  INT_7 = !((inputVal >> 6) & 1);  // Invertir el bit 6
  INT_8 = !((inputVal >> 7) & 1);  // Invertir el bit 7

}
