#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <math/mat4.h>
#include "display/color.h"

typedef struct window_s {
    SDL_Window *window;
    SDL_Renderer *renderer;
    uint32_t width, height;
} window_t;

window_t *window_init(const char *title, uint32_t width, uint32_t height);
void window_destroy(window_t *window);

void window_clear(const window_t *window, const color_t *color);
void window_update(const window_t *window);

void window_draw_line(const window_t *window, float x1, float y1, float x2, float y2, const color_t *color);
void window_draw_triangle(const window_t *window, float x1, float y1, float x2, float y2, float x3, float y3, const color_t *color);
