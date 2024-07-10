#include "math/vec2.h"

vec2_t vec2_init(float v)
{
    return (vec2_t){v, v};
}

vec2_t vec2_add(const vec2_t *a, const vec2_t *b)
{
    return (vec2_t){a->x + b->x, a->y + b->y};
}

vec2_t vec2_sub(const vec2_t *a, const vec2_t *b)
{
    return (vec2_t){a->x - b->x, a->y - b->y};
}

vec2_t vec2_mul(const vec2_t *a, const vec2_t *b)
{
    return (vec2_t){a->x * b->x, a->y * b->y};
}

vec2_t vec2_mulf(const vec2_t *a, float b)
{
    return (vec2_t){a->x * b, a->y * b};
}

float vec2_dot(const vec2_t *a, const vec2_t *b)
{
    return a->x * b->x + a->y * b->y;
}

float vec2_length(const vec2_t *a)
{
    return sqrtf(a->x * a->x + a->y * a->y);
}

vec2_t vec2_normalize(const vec2_t *a)
{
    float length = vec2_length(a);
    return (vec2_t){a->x / length, a->y / length};
}

vec2_t vec2_cross(const vec2_t *a, const vec2_t *b)
{
    return (vec2_t){
        a->x * b->y - a->y * b->x,
        a->y * b->x - a->x * b->y
    };
}
