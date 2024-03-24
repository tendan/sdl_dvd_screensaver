#include "loop.h"

void (*UpdateCoordinatesHandler)(int *x_step, int *y_step, SDL_Rect *rect);

void LinearBounce(int *x_step, int *y_step, SDL_Rect *rect) {
    int *x_pos = &rect->x;
    int *y_pos = &rect->y;
    const int *width = &rect->w;
    const int *height = &rect->h;

    if (*x_pos + *width >= WIDTH || *x_pos <= 0) *x_step = -(*x_step);

    *x_pos += *x_step;

    if (*y_pos + *height >= HEIGHT || *y_pos <= 0) *y_step = -(*y_step);

    *y_pos += *y_step;
}

void UpdateXY(int *x_step, int *y_step, SDL_Rect *rect, void (*UpdateCoordinatesHandler)(int*, int*, SDL_Rect*)) {
    UpdateCoordinatesHandler(x_step, y_step, rect);
}

void Loop(SDL_Renderer *renderer, SDL_Event *event) {
    short int tickrate = 0;
    int running = 1;
    SDL_Rect rect = CreateRectangle(renderer, 240, 120);
    int increasing_x = 1;
    int increasing_y = 1;
    while (running) {
        if (tickrate == TICK_RATE) {
            UpdateXY(&increasing_x, &increasing_y, &rect, LinearBounce);
            UpdateRectangle(renderer, &rect, rect.x, rect.y);
        }
        tickrate = (tickrate + 1) % (TICK_RATE + 1);

        while(SDL_PollEvent(event)) {
            switch (event->type) {
                case SDL_QUIT:
                {
                    running = 0;
                    break;
                }
            }
        }
    }
}