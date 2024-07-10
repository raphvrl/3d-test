#include "projection/camera.h"

camera_t *camera_init(vec3_t position)
{
    camera_t *camera = malloc(sizeof(camera_t));
    if (!camera) {
        return NULL;
    }

    camera->position = position;
    camera->front = (vec3_t){0.0f, 0.0f, 1.0f};
    camera->up = (vec3_t){0.0f, 1.0f, 0.0f};
    camera->right = (vec3_t){1.0f, 0.0f, 0.0f};

    camera->yaw = -90.0f;
    camera->pitch = 0.0f;

    camera->fov = 90.0f;

    camera->view = mat4_init(1.0f);
    camera->projection = mat4_init(1.0f);

    camera->near = 0.1f;
    camera->far = 100.0f;

    return camera;
}

void camera_update(camera_t *camera, float aspect)
{
    vec3_t front = {
        cosf(DEG_TO_RAD(camera->yaw)) * cosf(DEG_TO_RAD(camera->pitch)),
        sinf(DEG_TO_RAD(camera->pitch)),
        sinf(DEG_TO_RAD(camera->yaw)) * cosf(DEG_TO_RAD(camera->pitch))
    };

    camera->front = vec3_normalize(&front);
    vec3_t target = vec3_add(&camera->position, &camera->front);

    camera->view = mat4_set_view(&camera->position, &target, &camera->up);
    camera->projection = mat4_set_projection(camera->fov, aspect, camera->near, camera->far);
}

void camera_destroy(camera_t *camera)
{
    free(camera);
}

mat4_t mat4_set_projection(float fov, float aspect, float near, float far)
{
    mat4_t res = {0};

    res.m[0][0] = 1.0f / (aspect * tanf(fov / 2.0f));
    res.m[1][1] = 1.0f / tanf(fov / 2.0f);
    res.m[2][2] = -(far + near) / (far - near);
    res.m[2][3] = -1.0f;
    res.m[3][2] = -(2.0f * far * near) / (far - near);

    return res;
}

mat4_t mat4_set_view(const vec3_t *eye, const vec3_t *center, const vec3_t *up)
{
    vec3_t f = vec3_sub(center, eye);
    vec3_t cross = vec3_cross(up, &f);
    vec3_t r = vec3_normalize(&cross);
    vec3_t u = vec3_cross(&f, &r);

    mat4_t res = {0};
    res.m[0][0] = r.x;
    res.m[0][1] = r.y;
    res.m[0][2] = r.z;
    res.m[0][3] = -vec3_dot(&r, eye);

    res.m[1][0] = u.x;
    res.m[1][1] = u.y;
    res.m[1][2] = u.z;
    res.m[1][3] = -vec3_dot(&u, eye);

    res.m[2][0] = -f.x;
    res.m[2][1] = -f.y;
    res.m[2][2] = -f.z;
    res.m[2][3] = vec3_dot(&f, eye);

    res.m[3][3] = 1.0f;

    return res;
}
