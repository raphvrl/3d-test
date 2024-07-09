#include "display/event.h"

event_t event_init(void)
{
    return (event_t){0};
}

bool event_poll(event_t *event)
{
    return SDL_PollEvent(&event->event);
}

bool event_quit(const event_t *event)
{
    return event->event.type == SDL_QUIT;
}
