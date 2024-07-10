#include "projection/model.h"

model_t *model_init(const char *path)
{
    if (!path) {
        return NULL;
    }

    model_t *model = malloc(sizeof(model_t));
    if (!model) {
        return NULL;
    }

    model->transform = mat4_init(1.0f);
    model->mesh = mesh_init(path);

    return model;
}

void model_destroy(model_t *model)
{
    mesh_destroy(model->mesh);
    free(model);
}