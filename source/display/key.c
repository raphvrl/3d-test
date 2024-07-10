#include "display/key.h"

bool is_keydown(enum e_key key)
{
    const uint8_t *state = SDL_GetKeyboardState(NULL);
    return state[key];
}