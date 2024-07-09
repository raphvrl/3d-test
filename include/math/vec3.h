#pragma once

#include <stdio.h>
#include <math.h>

typedef struct vec3_s {
    float x, y, z;
} vec3_t;

vec3_t vec3_init(float v);

vec3_t vec3_add(const vec3_t *a, const vec3_t *b);
vec3_t vec3_sub(const vec3_t *a, const vec3_t *b);
vec3_t vec3_mul(const vec3_t *a, const vec3_t *b);
vec3_t vec3_div(const vec3_t *a, const vec3_t *b);

vec3_t vec3_addf(const vec3_t *a, float b);
vec3_t vec3_subf(const vec3_t *a, float b);
vec3_t vec3_mulf(const vec3_t *a, float b);
vec3_t vec3_divf(const vec3_t *a, float b);

float vec3_dot(const vec3_t *a, const vec3_t *b);
float vec3_length(const vec3_t *a);
vec3_t vec3_normalize(const vec3_t *a);
vec3_t vec3_cross(const vec3_t *a, const vec3_t *b);

void vec3_print(const vec3_t *a);
