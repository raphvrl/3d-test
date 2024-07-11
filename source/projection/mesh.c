#include "projection/mesh.h"

mesh_t *mesh_init(const char *path)
{
    if (!path) {
        return NULL;
    }

    mesh_t *mesh = malloc(sizeof(mesh_t));
    if (!mesh) {
        return NULL;
    }

    load_obj(path, mesh);

    return mesh;
}

void load_obj(char const *path, mesh_t *mesh)
{
    FILE *file = fopen(path, "r");
    if (!file) {
        free(mesh);
        return;
    }

    mesh->v_size = 0;
    mesh->i_size = 0;

    char line[256];
    while (fgets(line, 256, file)) {
        if (line[0] == 'v' && line[1] == ' ') {
            mesh->v_size++;
        } else if (line[0] == 'f') {
            mesh->i_size += 3;
        }
    }

    mesh->vertices = malloc(mesh->v_size * sizeof(vec3_t));
    mesh->indices = malloc(mesh->i_size * sizeof(uint32_t));
    if (!mesh->vertices || !mesh->indices) {
        fclose(file);
        return;
    }

    fseek(file, 0, SEEK_SET);

    uint32_t v_index = 0;
    uint32_t i_index = 0;

    while (fgets(line, 256, file)) {
        if (line[0] == 'v') {
            sscanf(line, "v  %f %f %f", &mesh->vertices[v_index].x, &mesh->vertices[v_index].y, &mesh->vertices[v_index].z);
            v_index++;
        } else if (line[0] == 'f') {
            sscanf(line, "f  %u/%*[^ ] %u/%*[^ ] %u/%*[^ ]", &mesh->indices[i_index], &mesh->indices[i_index + 1], &mesh->indices[i_index + 2]);
            i_index += 3;
        }
    }

    fclose(file);
}

vec4_t get_vertex(const mesh_t *mesh, uint32_t i)
{
    return vec4_init3(&mesh->vertices[mesh->indices[i] - 1], 1.0f);
}

vec2_t vertex_to_screen(const vec4_t *vertex, uint32_t width, uint32_t height)
{
    return (vec2_t){
        vertex->x * width / 2.0f + width / 2.0f,
        -vertex->y * height / 2.0f + height / 2.0f
    };
}

void mesh_destroy(mesh_t *mesh)
{
    free(mesh->vertices);
    free(mesh->indices);
    free(mesh);
}