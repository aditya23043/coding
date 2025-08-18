#include "Arduino.h"

// #include <oled.h>

// OLED display(D2, D1, NO_RESET_PIN, 0x3c, OLED::W_128, OLED::H_64, true);

// void setup() {
//     display.begin();
//     display.drawString(6, 8, "Something idk");
// }

// void loop() {}
#include "Wire.h"

void setup() {
    Wire.begin(D2, D1); // match your pins
    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.println("\nI2C Scanner");
}

void loop() {
    byte error, address;
    int nDevices = 0;

    for (address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0) {
            Serial.print("I2C device found at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.print(address, HEX);
            Serial.println();
            nDevices++;
        }
    }

    if (nDevices == 0)
        Serial.println("No I2C devices found");
    delay(5000);
}
