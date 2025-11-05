#include <Arduino.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#include "EPD_3in5g.h"
#include "ImageData.h"
#include "AdafruitFontsHelper.cpp"

void setup()
{
    DEV_Module_Init();

    EPD_3IN5G_Init_Fast();
    EPD_3IN5G_Clear(EPD_3IN5G_WHITE);

    EPD_3IN5G_Display(Image4color);

    delay(2000);

    const GFXfont *font = &FreeMonoBold9pt7b;
    drawStringToPaint(10, 10, "Lamborghini", font, EPD_3IN5G_WHITE);

    DEV_Module_Exit();
}

void loop() {}
