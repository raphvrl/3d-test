#pragma once

#include <math.h>

typedef struct vec2_s {
    float x, y;
} vec2_t;

vec2_t vec2_init(float v);

vec2_t vec2_add(const vec2_t *a, const vec2_t *b);
vec2_t vec2_sub(const vec2_t *a, const vec2_t *b);
vec2_t vec2_mul(const vec2_t *a, const vec2_t *b);
vec2_t vec2_mulf(const vec2_t *a, float b);

float vec2_dot(const vec2_t *a, const vec2_t *b);
float vec2_length(const vec2_t *a);
vec2_t vec2_normalize(const vec2_t *a);
vec2_t vec2_cross(const vec2_t *a, const vec2_t *b);
