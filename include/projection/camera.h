#pragma once

#include <stdlib.h>

#include "math/mat4.h"
#include "math/angle.h"

typedef struct camera_s {
    vec3_t position;
    vec3_t front;
    vec3_t up;
    vec3_t right;

    float sensitivity;
    float yaw;
    float pitch;
    float fov;

    float near;
    float far;

    mat4_t view;
    mat4_t projection;
} camera_t;

camera_t *camera_init(vec3_t position);

void camera_update(camera_t *camera, float aspect);
void camera_move_forward(camera_t *camera, float speed);
void camera_move_backward(camera_t *camera, float speed);
void camera_move_left(camera_t *camera, float speed);
void camera_move_right(camera_t *camera, float speed);
void camera_move_up(camera_t *camera, float speed);
void camera_move_down(camera_t *camera, float speed);
void camera_rotate(camera_t *camera, float xoffset, float yoffset);

void camera_destroy(camera_t *camera);

mat4_t mat4_set_projection(float fov, float aspect, float near, float far);
mat4_t mat4_set_view(const vec3_t *eye, const vec3_t *center, const vec3_t *up);
