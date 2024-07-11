#include "display/clock.h"

clock_t *clock_init(void)
{
    clock_t *clock = malloc(sizeof(clock_t));
    if (clock == NULL) {
        return NULL;
    }

    clock->start = SDL_GetTicks();
    clock->end = 0;
    clock->delta = 0;

    return clock;
}

void clock_update(clock_t *clock)
{
    clock->end = SDL_GetTicks();
    clock->delta = (clock->end - clock->start) / 1000;
    clock->start = clock->end;
    clock->fps = 1 / clock->delta;
}

void clock_destroy(clock_t *clock)
{
    free(clock);
}
