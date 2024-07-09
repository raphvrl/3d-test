#include "math/vec4.h"

vec4_t vec4_init(float v)
{
    return (vec4_t){v, v, v, v};
}

vec4_t vec4_init3(const vec3_t *v, float w)
{
    return (vec4_t){v->x, v->y, v->z, w};
}

vec4_t vec4_add(const vec4_t *a, const vec4_t *b)
{
    return (vec4_t){a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w};
}

vec4_t vec4_sub(const vec4_t *a, const vec4_t *b)
{
    return (vec4_t){a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w};
}

vec4_t vec4_mul(const vec4_t *a, const vec4_t *b)
{
    return (vec4_t){a->x * b->x, a->y * b->y, a->z * b->z, a->w * b->w};
}

vec4_t vec4_div(const vec4_t *a, const vec4_t *b)
{
    return (vec4_t){a->x / b->x, a->y / b->y, a->z / b->z, a->w / b->w};
}

vec4_t vec4_addf(const vec4_t *a, float b)
{
    return (vec4_t){a->x + b, a->y + b, a->z + b, a->w + b};
}

vec4_t vec4_subf(const vec4_t *a, float b)
{
    return (vec4_t){a->x - b, a->y - b, a->z - b, a->w - b};
}

vec4_t vec4_mulf(const vec4_t *a, float b)
{
    return (vec4_t){a->x * b, a->y * b, a->z * b, a->w * b};
}

vec4_t vec4_divf(const vec4_t *a, float b)
{
    return (vec4_t){a->x / b, a->y / b, a->z / b, a->w / b};
}

float vec4_dot(const vec4_t *a, const vec4_t *b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

float vec4_length(const vec4_t *a)
{
    return sqrtf(a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w);
}

vec4_t vec4_normalize(const vec4_t *a)
{
    float len = vec4_length(a);
    return (vec4_t){a->x / len, a->y / len, a->z / len, a->w / len};
}
