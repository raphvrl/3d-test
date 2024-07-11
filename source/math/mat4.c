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

mat4_t mat4_initv(const vec4_t *v)
{
    mat4_t res = {0};

    res.m[0][0] = v->x;
    res.m[1][1] = v->y;
    res.m[2][2] = v->z;
    res.m[3][3] = v->w;

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

mat4_t mat4_translate(const mat4_t *a, const vec3_t *t)
{
    mat4_t res = *a;

    res.m[0][0] = 1.0f;
    res.m[1][1] = 1.0f;
    res.m[2][2] = 1.0f;
    res.m[3][3] = 1.0f;
    res.m[3][0] += t->x;
    res.m[3][1] += t->y;
    res.m[3][2] += t->z;

    return mat4_mul(a, &res);
}

mat4_t mat4_scale(const mat4_t *a, const vec3_t *s)
{
    mat4_t res = *a;

    res.m[0][0] = s->x;
    res.m[1][1] = s->y;
    res.m[2][2] = s->z;
    res.m[3][3] = 1.0f;

    return mat4_mul(a, &res);
}

mat4_t mat4_rotate(const mat4_t *a, const vec3_t *r)
{
    mat4_t res = {0};

    float x = DEG_TO_RAD(r->x);
    float y = DEG_TO_RAD(r->y);
    float z = DEG_TO_RAD(r->z);

    float cx = cosf(x);
    float sx = sinf(x);
    float cy = cosf(y);
    float sy = sinf(y);
    float cz = cosf(z);
    float sz = sinf(z);

    res.m[0][0] = cy * cz;
    res.m[0][1] = cy * sz;
    res.m[0][2] = -sy;
    res.m[0][3] = 0.0f;

    res.m[1][0] = sx * sy * cz - cx * sz;
    res.m[1][1] = sx * sy * sz + cx * cz;
    res.m[1][2] = sx * cy;
    res.m[1][3] = 0.0f;

    res.m[2][0] = cx * sy * cz + sx * sz;
    res.m[2][1] = cx * sy * sz - sx * cz;
    res.m[2][2] = cx * cy;
    res.m[2][3] = 0.0f;

    res.m[3][0] = 0.0f;
    res.m[3][1] = 0.0f;
    res.m[3][2] = 0.0f;
    res.m[3][3] = 1.0f;

    return mat4_mul(a, &res);
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
