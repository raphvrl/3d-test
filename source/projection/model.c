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
    model->scale = vec3_init(1.0f);
    model->rotation = vec3_init(0.0f);
    model->model = mat4_init(1.0f);

    return model;
}

void model_update(model_t *model)
{
    model->model = mat4_init(1.0f);
    model->model = mat4_translate(&model->model, &model->position);
    model->model = mat4_scale(&model->model, &model->scale);
    model->model = mat4_rotate(&model->model, &model->rotation);
}

void model_render(const model_t *model, const window_t *window, const camera_t *camera)
{
    mat4_t mvp = mat4_mul(&camera->projection, &camera->view);
    mvp = mat4_mul(&mvp, &model->model);

    for (uint32_t i = 0; i < model->mesh->i_size; i += 3) {
        vec4_t p1 = get_vertex(model->mesh, i);
        vec4_t p2 = get_vertex(model->mesh, i + 1);
        vec4_t p3 = get_vertex(model->mesh, i + 2);

        p1 = mat4_mulv(&mvp, &p1);
        p2 = mat4_mulv(&mvp, &p2);
        p3 = mat4_mulv(&mvp, &p3);

        if ((p1.w <= camera->near) || (p2.w <= camera->near) || (p3.w <= camera->near) ||
            (p1.w >= camera->far) || (p2.w >= camera->far) || (p3.w >= camera->far)) {
            continue;
        }

        p1 = vec4_divf(&p1, p1.w);
        p2 = vec4_divf(&p2, p2.w);
        p3 = vec4_divf(&p3, p3.w);

        vec2_t s1 = vertex_to_screen(&p1, window->width, window->height);
        vec2_t s2 = vertex_to_screen(&p2, window->width, window->height);
        vec2_t s3 = vertex_to_screen(&p3, window->width, window->height);

        window_draw_triangle(window, &s1, &s2, &s3, &C_WHITE);
    }
}

void model_destroy(model_t *model)
{
    mesh_destroy(model->mesh);
    free(model);
}