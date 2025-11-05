#include "DEV_Config.h"
#include "GUI_Paint.h"
#include <stdint.h>
#include <Adafruit_GFX.h>

// -----------------------------------------------------------------------------
// Draw a single Adafruit GFX font character to the Paint buffer
// -----------------------------------------------------------------------------
void drawCharToPaint(int16_t x, int16_t y, char c, const GFXfont *font, UWORD color) {
    if (!font) return;
    if (c < font->first || c > font->last) return;

    GFXglyph *glyph  = font->glyph + (c - font->first);
    uint8_t  *bitmap = font->bitmap;

    uint16_t bo = glyph->bitmapOffset;
    uint8_t  w  = glyph->width;
    uint8_t  h  = glyph->height;
    int8_t   xo = glyph->xOffset;
    int8_t   yo = glyph->yOffset;

    uint8_t bits = 0, bit = 0;

    for (int16_t yy = 0; yy < h; yy++) {
        for (int16_t xx = 0; xx < w; xx++) {
            if (!(bit++ & 7)) bits = pgm_read_byte(&bitmap[bo++]);
            if (bits & 0x80) {
                Paint_SetPixel(x + xo + xx, y + yo + yy, color);
            }
            bits <<= 1;
        }
    }
}

// -----------------------------------------------------------------------------
// Draw a full string using Adafruit GFX font to the Paint buffer
// -----------------------------------------------------------------------------
void drawStringToPaint(int16_t x, int16_t y, const char *str, const GFXfont *font, UWORD color) {
    if (!font) return;
    int16_t cursorX = x;
    for (const char *p = str; *p; p++) {
        char c = *p;
        if (c == '\n') {
            y += font->yAdvance;
            cursorX = x;
            continue;
        }
        if (c < font->first || c > font->last) continue;
        GFXglyph *glyph = font->glyph + (c - font->first);
        drawCharToPaint(cursorX, y, c, font, color);
        cursorX += glyph->xAdvance;
    }
}

