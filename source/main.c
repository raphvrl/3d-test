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

    model_t *model = model_init("models/cube.obj");

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

        model_update(model);

        window_clear(window, &bg);

        model_render(model, window, camera);

        window_update(window);

        clock_update(clock);
    }

    model_destroy(model);
    window_destroy(window);
    camera_destroy(camera);

    return 0;
}
