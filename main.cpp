#include "includes.h"
int main(int argc, char *argv[]) {
  SDL_Window *window = NULL;
  SDL_Surface *screen_buffer = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "couldnt initialize SDL, error log:" << SDL_GetError();
  } else {
    window = SDL_CreateWindow("TerminalGameConsole", 0, 0, 640, 400,
                              SDL_WINDOW_SHOWN);
    if (window == NULL) {
      std::cout << "oopsy error while creating window, error log:"
                << SDL_GetError();
    } else {
      screen_buffer = SDL_GetWindowSurface(window);
      SDL_FillRect(screen_buffer, NULL,
                   SDL_MapRGB(screen_buffer->format, 0xFF, 0xFF, 0xFF));
      SDL_UpdateWindowSurface(window);
      SDL_Event e;
      bool quit = false;
      while (quit == false) {
        while (SDL_PollEvent(&e)) {
          if (e.type == SDL_QUIT)
            quit = true;
        }
      }
    }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
