#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        delay(10);
    }
    Serial.println("Hello from RP2040!");

    pinMode(15, INPUT_PULLUP);
    pinMode(16, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(16) == LOW) {
        Serial.println("HUH");
    }
    if (digitalRead(15) == LOW) {
        Serial.println("YES");
    }
    delay(1000);
}
