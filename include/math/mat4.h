#pragma once

#include <stdint.h>
#include <math/vec4.h>
#include <math/vec3.h>
#include <math/vec2.h>
#include <math/angle.h>

typedef struct mat4_s {
    float m[4][4];
} mat4_t;

mat4_t mat4_init(float d);
mat4_t mat4_initv(const vec4_t *v);

mat4_t mat4_add(const mat4_t *a, const mat4_t *b);
mat4_t mat4_sub(const mat4_t *a, const mat4_t *b);
mat4_t mat4_mul(const mat4_t *a, const mat4_t *b);

vec4_t mat4_mulv(const mat4_t *a, const vec4_t *b);

mat4_t mat4_translate(const mat4_t *a, const vec3_t *t);
mat4_t mat4_scale(const mat4_t *a, const vec3_t *s);
mat4_t mat4_rotate(const mat4_t *a, const vec3_t *r);

void mat4_print(const mat4_t *a);
