#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

Adafruit_NeoPixel rgb(1, 16, NEO_GRB + NEO_KHZ800);

void setup() { rgb.begin(); }

void loop() {
    rgb.clear();

    rgb.setPixelColor(1, 255, 255, 255);
    rgb.show();

    delay(100);
}
