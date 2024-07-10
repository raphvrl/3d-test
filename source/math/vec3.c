#include "math/vec3.h"

vec3_t vec3_init(float v)
{
    return (vec3_t){v, v, v};
}

vec3_t vec3_add(const vec3_t *a, const vec3_t *b)
{
    return (vec3_t){a->x + b->x, a->y + b->y, a->z + b->z};
}

vec3_t vec3_sub(const vec3_t *a, const vec3_t *b)
{
    return (vec3_t){a->x - b->x, a->y - b->y, a->z - b->z};
}

vec3_t vec3_mul(const vec3_t *a, const vec3_t *b)
{
    return (vec3_t){a->x * b->x, a->y * b->y, a->z * b->z};
}

vec3_t vec3_div(const vec3_t *a, const vec3_t *b)
{
    if (b->x == 0 || b->y == 0 || b->z == 0) {
        return (vec3_t){0};
    }

    return (vec3_t){a->x / b->x, a->y / b->y, a->z / b->z};
}

vec3_t vec3_addf(const vec3_t *a, float b)
{
    return (vec3_t){a->x + b, a->y + b, a->z + b};
}

vec3_t vec3_subf(const vec3_t *a, float b)
{
    return (vec3_t){a->x - b, a->y - b, a->z - b};
}

vec3_t vec3_mulf(const vec3_t *a, float b)
{
    return (vec3_t){a->x * b, a->y * b, a->z * b};
}

vec3_t vec3_divf(const vec3_t *a, float b)
{
    if (b == 0) {
        return (vec3_t){0};
    }

    return (vec3_t){a->x / b, a->y / b, a->z / b};
}

float vec3_dot(const vec3_t *a, const vec3_t *b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

float vec3_length(const vec3_t *a)
{
    return sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
}

vec3_t vec3_normalize(const vec3_t *a)
{
    float len = vec3_length(a);
    return (vec3_t){a->x / len, a->y / len, a->z / len};
}

vec3_t vec3_cross(const vec3_t *a, const vec3_t *b)
{
    return (vec3_t){
        a->y * b->z - a->z * b->y,
        a->z * b->x - a->x * b->z,
        a->x * b->y - a->y * b->x
    };
}

void vec3_print(const vec3_t *a)
{
    printf("vec3: (%f, %f, %f)\n", a->x, a->y, a->z);
}
