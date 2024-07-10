#pragma once

#include <stdlib.h>

#include "display/window.h"
#include "projection/camera.h"
#include "projection/mesh.h"


typedef struct model_s {
    mat4_t transform;
    mesh_t *mesh;
} model_t;

model_t *model_init(const char *path);

void model_destroy(model_t *model);