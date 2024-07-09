#pragma once

#include <math.h>
#include <stdio.h>

#include "math/vec3.h"

typedef struct vec4_s {
    float x, y, z, w;
} vec4_t;

vec4_t vec4_init(float v);
vec4_t vec4_init3(const vec3_t *v, float w);

vec4_t vec4_add(const vec4_t *a, const vec4_t *b);
vec4_t vec4_sub(const vec4_t *a, const vec4_t *b);
vec4_t vec4_mul(const vec4_t *a, const vec4_t *b);
vec4_t vec4_div(const vec4_t *a, const vec4_t *b);

vec4_t vec4_addf(const vec4_t *a, float b);
vec4_t vec4_subf(const vec4_t *a, float b);
vec4_t vec4_mulf(const vec4_t *a, float b);
vec4_t vec4_divf(const vec4_t *a, float b);

float vec4_dot(const vec4_t *a, const vec4_t *b);
float vec4_length(const vec4_t *a);
vec4_t vec4_normalize(const vec4_t *a);
vec4_t vec4_cross(const vec4_t *a, const vec4_t *b);
