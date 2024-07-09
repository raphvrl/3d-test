#pragma once

#include <stdint.h>

#define C_WHITE (color_t){255, 255, 255, 255}
#define C_BLACK (color_t){0, 0, 0, 255}

typedef struct color_s {
    uint8_t r, g, b, a;
} color_t;
