#include "draw.h"

SDL_Rect CreateRectangle(SDL_Renderer *renderer, int width, int height) {
    char buff[20];
    SDL_Rect rect;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    rect.h = height;
    rect.w = width;
    rect.y = HEIGHT * 0.5 - 50;
    rect.x = WIDTH * 0.5 - 50;
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    return rect;
}

void UpdateRectangle(SDL_Renderer *renderer, SDL_Rect *rect, int new_x, int new_y) {
    SDL_RenderClear(renderer);

    rect->y = new_y;
    rect->x = new_x;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}