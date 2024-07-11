#pragma once

#include <stdlib.h>

#include "display/window.h"
#include "projection/camera.h"
#include "projection/mesh.h"


typedef struct model_s {
    mat4_t model;
    vec3_t position;
    vec3_t scale;
    mesh_t *mesh;

    float pitch, yaw, roll;
} model_t;

model_t *model_init(const char *path);

void model_update(model_t *model);
void model_render(const model_t *model, const window_t *window, const camera_t *camera);

void model_destroy(model_t *model);