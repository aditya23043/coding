#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

int main(int argc, char *argv[]) {

  SDL_Window *window = NULL;
  SDL_Surface *surface = NULL;

  window = SDL_CreateWindow("Something", 10, 10, 260, 250, NULL);

  return 0;
}
