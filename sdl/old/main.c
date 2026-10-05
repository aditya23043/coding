#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {

  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderDrawPoint(renderer, 640/2, 480/2);

  SDL_RenderPresent(renderer);

  SDL_Delay(10000);


  return 0;
}
