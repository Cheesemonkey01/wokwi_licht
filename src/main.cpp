#include <Arduino.h>
#define N_PINS   5
#define BAUDRATE 9600         //Anzahl der übertragenden Symbole in einer Sekunde
#define T_ON     100
#define T_OFF    400
#define T_WAIT   3000

      //Globale Variable
      uint8_t pinLed[]={6, 7, 8, 9, 10};

      // In einem Programm werden keine festen Werte innerhalb eines Codes verwendet!!!


void setup()
{     
      Serial.begin(BAUDRATE);

      //Set Pins as OUTPUT
      for (uint8_t i = 0; i < N_PINS; ++i){
            pinMode(pinLed[i], OUTPUT);
      }
}

void loop()
{   

    for (uint8_t i = 0; i <N_PINS; ++i){
            digitalWrite(pinLed[i], HIGH);
            delay(T_ON);
            digitalWrite(pinLed[i], LOW);
            delay(T_OFF);
      }
      delay(T_WAIT);
}