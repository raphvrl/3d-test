#pragma once

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct event_s {
    SDL_Event event;
} event_t;

enum e_key {
    K_UP = SDLK_UP,
    K_DOWN = SDLK_DOWN,
    K_LEFT = SDLK_LEFT,
    K_RIGHT = SDLK_RIGHT,
    K_ESCAPE = SDLK_ESCAPE,
    K_SPACE = SDLK_SPACE,
    K_CTRL = SDLK_LCTRL,
    K_SHIFT = SDLK_LSHIFT,
    K_ALT = SDLK_LALT,
    K_TAB = SDLK_TAB,
    K_A = SDLK_a,
    K_B = SDLK_b,
    K_C = SDLK_c,
    K_D = SDLK_d,
    K_E = SDLK_e,
    K_F = SDLK_f,
    K_G = SDLK_g,
    K_H = SDLK_h,
    K_I = SDLK_i,
    K_J = SDLK_j,
    K_K = SDLK_k,
    K_L = SDLK_l,
    K_M = SDLK_m,
    K_N = SDLK_n,
    K_O = SDLK_o,
    K_P = SDLK_p,
    K_Q = SDLK_q,
    K_R = SDLK_r,
    K_S = SDLK_s,
    K_T = SDLK_t,
    K_U = SDLK_u,
    K_V = SDLK_v,
    K_W = SDLK_w,
    K_X = SDLK_x,
    K_Y = SDLK_y,
    K_Z = SDLK_z
};

event_t event_init(void);

bool event_poll(event_t *event);
bool event_quit(const event_t *event);
bool event_keydown(const event_t *event, enum e_key key);
