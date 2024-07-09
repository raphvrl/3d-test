#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "display/color.h"

typedef struct window_s {
    SDL_Window *window;
    SDL_Renderer *renderer;
} window_t;

window_t *window_init(const char *title, uint32_t width, uint32_t height);
void window_destroy(window_t *window);

void window_clear(const window_t *window, const color_t *color);
void window_update(const window_t *window);
