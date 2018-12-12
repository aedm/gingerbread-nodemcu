#include <Arduino.h>

const int pins[] = {D0, D1, D2, D3, D4, D5, D6, D7, D8};

void setup() {
  for (auto pin : pins) {
    pinMode(pin, OUTPUT);
  }
  Serial.begin(9600);
}

int currentLed = 0;
int delta = -1;

void loop() {
  for (int i=0; i<9; i++) {
    digitalWrite(pins[i], i == currentLed ? LOW : HIGH);
  }
  
  if (currentLed == 0 || currentLed == 8) {
    delta = -delta;
  }
  currentLed += delta;

  Serial.printf("Value is:%3d\n", currentLed);

  delay(100);
}