#pragma once

#include <stdlib.h>
#include <stdint.h>
#include "math/mat4.h"

typedef struct mesh_s {
    vec3_t *vertices;
    uint32_t v_size;
    uint32_t *indices;
    uint32_t i_size;
} mesh_t;

mesh_t *mesh_init(const char *path);

void load_obj(const char *path, mesh_t *mesh);

vec4_t get_vertex(const mesh_t *mesh, uint32_t i);
vec2_t vertex_to_screen(const vec4_t *vertex, uint32_t width, uint32_t height);

void mesh_destroy(mesh_t *mesh);
