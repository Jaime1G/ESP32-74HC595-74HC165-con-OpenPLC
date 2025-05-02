#include "HC165.h"

// Constructor de la clase HC165
HC165::HC165(int dataPin, int clockPin, int latchPin) {
  _dataPin = dataPin;
  _clockPin = clockPin;
  _latchPin = latchPin;
}

// Inicializa los pines
void HC165::begin() {
  pinMode(_dataPin, INPUT);
  pinMode(_clockPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
}

// Lee los 8 bits del HC165
uint8_t HC165::read() {
  uint8_t value = 0;

  // Cargar los datos del registro de desplazamiento
  digitalWrite(_latchPin, LOW);  // Preparar para la lectura
  digitalWrite(_latchPin, HIGH); // Capturar los datos
  delayMicroseconds(10);         // Esperar a que los datos se estabilicen

  // Leer los 8 bits
  for (int i = 7; i >= 0; i--) {
    digitalWrite(_clockPin, LOW);
    if (digitalRead(_dataPin)) {
      value |= (1 << i);  // Establecer el bit correspondiente a 1
    }
    digitalWrite(_clockPin, HIGH);
  }

  return value;  // Devuelve el valor de los 8 bits
}

