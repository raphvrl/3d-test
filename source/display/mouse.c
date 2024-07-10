#include "display/mouse.h"

vec2_t get_mouse_pos(void)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    return (vec2_t){x, y};
}

vec2_t get_mouse_mov(void)
{
    int x, y;
    SDL_GetRelativeMouseState(&x, &y);
    return (vec2_t){x, y};
}