#include "math/mat4.h"

mat4_t mat4_init(float d)
{
    mat4_t res = {0};

    res.m[0][0] = d;
    res.m[1][1] = d;
    res.m[2][2] = d;
    res.m[3][3] = d;

    return res;
}

mat4_t mat4_add(const mat4_t *a, const mat4_t *b)
{
    mat4_t c = {0};

    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 4; j++) {
            c.m[i][j] = a->m[i][j] + b->m[i][j];
        }
    }

    return c;
}

mat4_t mat4_sub(const mat4_t *a, const mat4_t *b)
{
    mat4_t c = {0};

    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 4; j++) {
            c.m[i][j] = a->m[i][j] - b->m[i][j];
        }
    }

    return c;
}

mat4_t mat4_mul(const mat4_t *a, const mat4_t *b)
{
    mat4_t c = {0};

    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 4; j++) {
            for (uint8_t k = 0; k < 4; k++) {
                c.m[i][j] += a->m[i][k] * b->m[k][j];
            }
        }
    }

    return c;
}

vec4_t mat4_mulv(const mat4_t *a, const vec4_t *b)
{
    vec4_t c = {0};

    c = (vec4_t){
        a->m[0][0] * b->x + a->m[0][1] * b->y + a->m[0][2] * b->z + a->m[0][3] * b->w,
        a->m[1][0] * b->x + a->m[1][1] * b->y + a->m[1][2] * b->z + a->m[1][3] * b->w,
        a->m[2][0] * b->x + a->m[2][1] * b->y + a->m[2][2] * b->z + a->m[2][3] * b->w,
        a->m[3][0] * b->x + a->m[3][1] * b->y + a->m[3][2] * b->z + a->m[3][3] * b->w
    };

    return c;
}

mat4_t mat4_rotate_x(const mat4_t *m, float a)
{
    mat4_t res = {0};

    res.m[0][0] = 1.0f;
    res.m[1][1] = cosf(a);
    res.m[1][2] = -sinf(a);
    res.m[2][1] = sinf(a);
    res.m[2][2] = cosf(a);
    res.m[3][3] = 1.0f;

    return mat4_mul(m, &res);
}

mat4_t mat4_rotate_y(const mat4_t *m, float a)
{
    mat4_t res = {0};

    res.m[0][0] = cosf(a);
    res.m[0][2] = sinf(a);
    res.m[1][1] = 1.0f;
    res.m[2][0] = -sinf(a);
    res.m[2][2] = cosf(a);
    res.m[3][3] = 1.0f;

    return mat4_mul(m, &res);
}

mat4_t mat4_rotate_z(const mat4_t *m, float a)
{
    mat4_t res = {0};

    res.m[0][0] = cosf(a);
    res.m[0][1] = -sinf(a);
    res.m[1][0] = sinf(a);
    res.m[1][1] = cosf(a);
    res.m[2][2] = 1.0f;
    res.m[3][3] = 1.0f;

    return mat4_mul(m, &res);
}

void mat4_print(const mat4_t *a)
{
    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 4; j++) {
            printf("%f ", a->m[i][j]);
        }

        printf("\n");
    }
}
