#pragma once

#include <stdint.h>
#include <math/vec4.h>
#include <math/vec3.h>
#include <math/vec2.h>

typedef struct mat4_s {
    float m[4][4];
} mat4_t;

mat4_t mat4_init(float d);
mat4_t mat4_initv(const vec4_t *v);

mat4_t mat4_add(const mat4_t *a, const mat4_t *b);
mat4_t mat4_sub(const mat4_t *a, const mat4_t *b);
mat4_t mat4_mul(const mat4_t *a, const mat4_t *b);

vec4_t mat4_mulv(const mat4_t *a, const vec4_t *b);

mat4_t mat4_translate(const mat4_t *a, const vec3_t *v);
mat4_t mat4_scale(const mat4_t *a, const vec3_t *v);
mat4_t mat4_rotate_x(const mat4_t *a, float angle);
mat4_t mat4_rotate_y(const mat4_t *a, float angle);
mat4_t mat4_rotate_z(const mat4_t *a, float angle);

void mat4_print(const mat4_t *a);
