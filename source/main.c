#include "display/window.h"
#include "display/event.h"
#include "projection/camera.h"
#include "display/key.h"
#include "display/mouse.h"
#include "display/clock.h"

int main(void)
{
    window_t *window = window_init("3D", 800, 600);
    if (!window) {
        return 1;
    }

    event_t event = event_init();
    color_t bg = C_BLACK;
    color_t white = C_WHITE;

    vec3_t vertices[] = {
        {0.5f, 0.5f, 0.5f},
        {-0.5f, 0.5f, 0.5f},
        {-0.5f, -0.5f, 0.5f},
        {0.5f, -0.5f, 0.5f},
        {0.5f, 0.5f, -0.5f},
        {-0.5f, 0.5f, -0.5f},
        {-0.5f, -0.5f, -0.5f},
        {0.5f, -0.5f, -0.5f}
    };

    uint32_t edges[] = {
        0, 1,
        1, 2,
        2, 3,
        3, 0,
        4, 5,
        5, 6,
        6, 7,
        7, 4,
        0, 4,
        1, 5,
        2, 6,
        3, 7
    };

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

        mat4_t model = mat4_init(1.0f);

        camera_update(camera, (float)window->width / (float)window->height);

        window_clear(window, &bg);

        for (uint32_t i = 0; i < 12; i++) {
            vec3_t  v1 = vertices[edges[i * 2]];
            vec3_t  v2 = vertices[edges[i * 2 + 1]];

            vec4_t t1 = {v1.x, v1.y, v1.z, 1.0f};
            vec4_t t2 = {v2.x, v2.y, v2.z, 1.0f};

            mat4_t tmp = mat4_mul(&camera->projection, &camera->view);
            tmp = mat4_mul(&tmp, &model);

            vec4_t p1 = mat4_mulv(&tmp, &t1);
            vec4_t p2 = mat4_mulv(&tmp, &t2);

            if (p1.w < 0.0f || p2.w < 0.0f) {
                continue;
            }

            p1 = vec4_divf(&p1, p1.w);
            p2 = vec4_divf(&p2, p2.w);

            p1.x = p1.x * window->width / 2.0f + window->width / 2.0f;
            p1.y = -p1.y * window->height / 2.0f + window->height / 2.0f;

            p2.x = p2.x * window->width / 2.0f + window->width / 2.0f;
            p2.y = -p2.y * window->height / 2.0f + window->height / 2.0f;

            window_draw_line(window, p1.x, p1.y, p2.x, p2.y, &white);
        }

        window_update(window);

        clock_update(clock);
    }

    window_destroy(window);
    camera_destroy(camera);

    return 0;
}
