#include "display/window.h"
#include "display/event.h"
#include "projection/camera.h"
#include "display/key.h"
#include "display/mouse.h"
#include "display/clock.h"
#include "projection/model.h"

int main(void)
{
    window_t *window = window_init("3D", 800, 600);
    if (!window) {
        return 1;
    }

    event_t event = event_init();
    color_t bg = C_BLACK;
    color_t white = C_WHITE;

    model_t *model = model_init("models/poly.obj");

    camera_t *camera = camera_init((vec3_t){0.0f, 0.0f, 3.0f});

    bool running = true;

    clock_t *clock = clock_init(); 

    while (running) {
        while (event_poll(&event)) {
            if (event_quit(&event)) {
                running = false;
            }
        }

        float speed = 1.0f * clock->delta;

        if (is_keydown(K_ESCAPE)) {
            running = false;
        }

        if (is_keydown(K_W)) {
            camera_move_forward(camera, speed);
        }

        if (is_keydown(K_S)) {
            camera_move_backward(camera, speed);
        }

        if (is_keydown(K_A)) {
            camera_move_left(camera, speed);
        }

        if (is_keydown(K_D)) {
            camera_move_right(camera, speed);
        }

        if (is_keydown(K_SPACE)) {
            camera_move_up(camera, speed);
        }

        if (is_keydown(K_LSHIFT)) {
            camera_move_down(camera, speed);
        }

        vec2_t mov = get_mouse_mov();
        camera_rotate(camera, mov.x, mov.y);

        camera_update(camera, (float)window->width / (float)window->height);

        window_clear(window, &bg);

        mesh_t *mesh = model->mesh;

        // indice and vertice of .obj
        for (uint32_t i = 0; i < mesh->i_size; i += 3) {

            vec3_t v1 = mesh->vertices[mesh->indices[i] - 1];
            vec3_t v2 = mesh->vertices[mesh->indices[i + 1] - 1];
            vec3_t v3 = mesh->vertices[mesh->indices[i + 2] - 1];

            mat4_t mvp = mat4_mul(&camera->projection, &camera->view);
            mvp = mat4_mul(&mvp, &model->transform);

            vec4_t p1 = vec4_init3(&v1, 1.0f);
            vec4_t p2 = vec4_init3(&v2, 1.0f);
            vec4_t p3 = vec4_init3(&v3, 1.0f);

            p1 = mat4_mulv(&mvp, &p1);
            p2 = mat4_mulv(&mvp, &p2);
            p3 = mat4_mulv(&mvp, &p3);

            p1 = vec4_divf(&p1, p1.w);
            p2 = vec4_divf(&p2, p2.w);
            p3 = vec4_divf(&p3, p3.w);

            p1.x = p1.x * window->width / 2 + window->width / 2;
            p1.y = -p1.y * window->height / 2 + window->height / 2;

            p2.x = p2.x * window->width / 2 + window->width / 2;
            p2.y = -p2.y * window->height / 2 + window->height / 2;

            p3.x = p3.x * window->width / 2 + window->width / 2;
            p3.y = -p3.y * window->height / 2 + window->height / 2;

            window_draw_line(window, p1.x, p1.y, p2.x, p2.y, &white);
            window_draw_line(window, p2.x, p2.y, p3.x, p3.y, &white);
            window_draw_line(window, p3.x, p3.y, p1.x, p1.y, &white);
        }



        window_update(window);

        clock_update(clock);
    }

    model_destroy(model);
    window_destroy(window);
    camera_destroy(camera);

    return 0;
}
