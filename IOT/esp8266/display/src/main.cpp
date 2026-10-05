#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <SPI.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI D7
#define OLED_CLK D5
#define OLED_DC D1
#define OLED_CS D8
#define OLED_RESET D3

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK,
// OLED_DC, OLED_RESET, OLED_CS);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET,
                         OLED_CS, 10000000UL);

void testscrolltext(void);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0, true, true);

    display.display();

    delay(2);

    display.print("something");

    display.clearDisplay();

    testscrolltext();
}

void loop() {}

void testscrolltext(void) {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println(("VDF Assignment"));
    display.display();
    delay(100);

    while(1)
    {
      display.startscrolldiagright(0x00, 0x07);
    }

    display.stopscroll();
}
