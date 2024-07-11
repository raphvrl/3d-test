#pragma once

#include <SDL2/SDL.h>

typedef struct clock_s {
    float start;
    float end;
    float delta;
    float fps;
} clock_t;

clock_t *clock_init(void);

void clock_update(clock_t *clock);

void clock_destroy(clock_t *clock);
