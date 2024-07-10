#pragma once

#include <stdlib.h>
#include <stdint.h>
#include "math/vec3.h"

typedef struct mesh_s {
    vec3_t *vertices;
    uint32_t v_size;
    uint32_t *indices;
    uint32_t i_size;
} mesh_t;

mesh_t *mesh_init(const char *path);

void load_obj(const char *path, mesh_t *mesh);

void mesh_destroy(mesh_t *mesh);
