#include "include_sdl.h"
#include "loop.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer;

int main(int argc, char **argv) {
    InitSetup(&window, &renderer);

    SDL_Event event;

    Loop(renderer, &event);

    FinishOff(window, renderer);
}