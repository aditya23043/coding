#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Wire.h>
#include <cstring.h>

TwoWire myWire(14, 15);
Adafruit_SSD1306 display(128, 64, &myWire, -1);
const char *tasks[] = {
    "EVS Project Rerport (4th Nov)",   "VDF Assignment 4 (14th Nov)",
    "DVD Project Showcase (10th Nov)", "CMOS Project Showcase",
    "End sem examination (1st Dec)",
};

int current_task = 0;
int button_one_down = 0;
int button_two_down = 0;

int16_t x, y;
uint16_t w, h;

#define BUTTON1 0
#define BUTTON2 1
#define DELTA 4

void setup() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }

    pinMode(BUTTON1, INPUT_PULLUP);
    pinMode(BUTTON2, INPUT_PULLUP);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 0);
    display.display();
}

void loop() {

    if (digitalRead(BUTTON1) == 0) {
        if (!button_one_down) {
            current_task--;
            button_one_down = 1;
        }
    } else {
        button_one_down = 0;
    }

    if (digitalRead(BUTTON2) == 0) {
        if (!button_two_down) {
            current_task++;
            button_two_down = 1;
        }
    } else {
        button_two_down = 0;
    }

    if (current_task < 0)
        current_task = sizeof(tasks) / sizeof(tasks[0]) - 1;
    if (current_task > (int)(sizeof(tasks) / sizeof(tasks[0]) - 1))
        current_task = 0;

    display.clearDisplay();
    display.getTextBounds(tasks[current_task], 0, 0, &x, &y, &w, &h);
    display.setCursor(0, 0);

    strcat

        display.println(tasks[current_task]);

    display.display();

    delay(10);
}
