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

    model->mesh = mesh_init(path);
    model->position = vec3_init(0.0f);

    return model;
}

void model_update(model_t *model)
{
    model->model = mat4_init(1.0f);
    model->model = mat4_rotate_x(&model->model, model->pitch);
    model->model = mat4_rotate_y(&model->model, model->yaw);
    model->model = mat4_rotate_z(&model->model, model->roll);
}

void model_render(const model_t *model, const window_t *window, const camera_t *camera)
{
    mat4_t mvp = mat4_mul(&camera->projection, &camera->view);
    mvp = mat4_mul(&mvp, &model->model);

    for (uint32_t i = 0; i < model->mesh->i_size; i += 3) {
        vec4_t p1 = vec4_init3(&model->mesh->vertices[model->mesh->indices[i] - 1], 1.0f);
        vec4_t p2 = vec4_init3(&model->mesh->vertices[model->mesh->indices[i + 1] - 1], 1.0f);
        vec4_t p3 = vec4_init3(&model->mesh->vertices[model->mesh->indices[i + 2] - 1], 1.0f);

        p1 = mat4_mulv(&mvp, &p1);
        p2 = mat4_mulv(&mvp, &p2);
        p3 = mat4_mulv(&mvp, &p3);

        if (p1.w <= 0 || p2.w <= 0 || p3.w <= 0) {
            continue;
        }

        p1 = vec4_divf(&p1, p1.w);
        p2 = vec4_divf(&p2, p2.w);
        p3 = vec4_divf(&p3, p3.w);

        p1.x = p1.x * window->width / 2 + window->width / 2;
        p1.y = -p1.y * window->height / 2 + window->height / 2;

        p2.x = p2.x * window->width / 2 + window->width / 2;
        p2.y = -p2.y * window->height / 2 + window->height / 2;

        p3.x = p3.x * window->width / 2 + window->width / 2;
        p3.y = -p3.y * window->height / 2 + window->height / 2;

        window_draw_line(window, p1.x, p1.y, p2.x, p2.y, &C_WHITE);

        window_draw_line(window, p2.x, p2.y, p3.x, p3.y, &C_WHITE);

        window_draw_line(window, p3.x, p3.y, p1.x, p1.y, &C_WHITE);
    }
}

void model_destroy(model_t *model)
{
    mesh_destroy(model->mesh);
    free(model);
}