#pragma once

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "display/key.h"
#include "math/vec2.h"

typedef struct event_s {
    SDL_Event event;
} event_t;

event_t event_init(void);

bool event_poll(event_t *event);
bool event_quit(const event_t *event);
