#include <SDL2/SDL.h>
#include <stdint.h>
#include "../src/ImageData.h"

#define WIDTH 384
#define HEIGHT 184

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("C Array Image",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 0);
    SDL_Texture *tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGB888,
        SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    uint32_t pixels[WIDTH * HEIGHT];
    SDL_PixelFormat *fmt = SDL_AllocFormat(SDL_PIXELFORMAT_RGB888);

    // Color map for 4 colors (adjust for your display’s palette)
    uint8_t colors[4][3] = {
        {255, 255, 255}, // white
        {192, 192, 192}, // light gray
        {96, 96, 96},    // dark gray
        {0, 0, 0}        // black
    };

    int pixel_index = 0;
    for (int i = 0; i < 17644; i++) {
        uint8_t byte = Image4color[i];

        // 4 pixels per byte (2 bits each)
        for (int bit = 0; bit < 4; bit++) {
            uint8_t val = (byte >> ((3 - bit) * 2)) & 0x03;
            if (pixel_index >= WIDTH * HEIGHT) break;

            uint8_t *c = colors[val];
            pixels[pixel_index++] = SDL_MapRGB(fmt, c[0], c[1], c[2]);
        }
    }

    SDL_UpdateTexture(tex, NULL, pixels, WIDTH * sizeof(uint32_t));
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);

    SDL_Delay(5000);
    SDL_Quit();
    return 0;
}
