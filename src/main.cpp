#include <Arduino.h>

#define BAUDRATE 9600

// Global Variables
uint8_t pinLed[] = {5, 6, 7, 8, 9, 10};

// Data from User
uint8_t tones[] = {0, 1, 2, 3, 4, 4, 5, 5, 5, 5, 4, 5, 5, 5, 5, 4, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1, 0};
float   tOn[] = {0.5, 0.5, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, 0.5, 0.5, 1.0, 0.5, 0.5, 0.5, 0.5, 1.0, 0.5, 0.5, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, 0.5, 0.5, 2.0};
#define T_WAIT 3000
#define N_TONES sizeof(tones) / sizeof(tones[0])
#define N_PINS  sizeof(pinLed) / sizeof(pinLed[0])

void setup() {
  Serial.begin(BAUDRATE);
  // Set Pins as Output
  for (uint8_t i = 0; i < N_PINS; i++) {
     pinMode( pinLed[i], OUTPUT);
  }
}

void loop() {

  for (uint8_t i = 0; i < N_TONES; i++) {
    uint8_t pinInPinlist = tones[i];
    digitalWrite(pinLed[pinInPinlist], HIGH);
    delay(tOn[i]*1000);
    digitalWrite(pinLed[pinInPinlist], LOW);
  }
  delay(T_WAIT);
}