#include "Adafruit_TinyUSB.h"
#include "regs/spi.h"
#include <Arduino.h>

/*
28 27 26 09
22 06 19 21
07 18 20 08
*/

#define PIN 28

int pins[] = {28, 27, 26, 9, 22, 6, 19, 21, 07, 18, 20, 8};

int mappings[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};

const int numPins = sizeof(pins) / sizeof(pins[0]);

bool key_down = false;

void setup() {

    pinMode(LED_BUILTIN, OUTPUT);
    for (int i = 0; i < numPins; i++) {
        pinMode(pins[i], INPUT_PULLUP);
    }
}

void loop() {

    for (int i = 0; i < numPins; i++) {
        if (digitalRead(pins[i]) == LOW) {
            Keyboard.press(mappings[i]);
        }
    }

    delay(10);
}
