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

bool event_keydown(const event_t *event, enum e_key key)
{
    SDL_Keycode sdl_key = key;
    return event->event.type == SDL_KEYDOWN && event->event.key.keysym.sym == sdl_key;
}
