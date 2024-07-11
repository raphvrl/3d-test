#include "display/window.h"

window_t *window_init(const char *title, uint32_t width, uint32_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        return NULL;
    }

    window_t *window = malloc(sizeof(window_t));
    if (!window) {
        return NULL;
    }

    window->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window->window) {
        free(window);
        return NULL;
    }

    window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);
    if (!window->renderer) {
        SDL_DestroyWindow(window->window);
        free(window);
        return NULL;
    }

    SDL_SetRelativeMouseMode(SDL_TRUE);

    window->width = width;
    window->height = height;

    return window;
}

void window_destroy(window_t *window)
{
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->window);
    free(window);
}

void window_clear(const window_t *window, const color_t *color)
{
    SDL_SetRenderDrawColor(window->renderer, color->r, color->g, color->b, color->a);
    SDL_RenderClear(window->renderer);
}

void window_update(const window_t *window)
{
    SDL_RenderPresent(window->renderer);
}

void window_draw_line(const window_t *window, float x1, float y1, float x2, float y2, const color_t *color)
{
    SDL_SetRenderDrawColor(window->renderer, color->r, color->g, color->b, color->a);
    SDL_RenderDrawLine(window->renderer, x1, y1, x2, y2);
}

void window_draw_triangle(const window_t *window, float x1, float y1, float x2, float y2, float x3, float y3, const color_t *color)
{
    SDL_SetRenderDrawColor(window->renderer, color->r, color->g, color->b, color->a);
    SDL_RenderDrawLine(window->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(window->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(window->renderer, x3, y3, x1, y1);
}
