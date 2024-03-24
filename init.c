#include "init.h"

void SetCaption(SDL_Window *window, char *message) {
    SDL_SetWindowTitle(window, message);
}

void InitSetup(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_SHOWN, window, renderer);

    if (window == NULL) {
        fprintf(stderr, "InitSetup failed to create window");
    }
    
    SetCaption(*window, "Example One");
}

void FinishOff(SDL_Window *window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    exit(0);
}