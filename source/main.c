#include "display/window.h"
#include "display/event.h"
#include "math/vec3.h"

int main(void)
{
    window_t *window = window_init("3D", 800, 600);
    if (!window) {
        return 1;
    }

    event_t event = event_init();
    color_t bg = C_BLACK;
    color_t c_white = C_WHITE;

    vec3_t vertices[] = {
        {0.0f, 0.5f, 0.0f},
        {0.5f, -0.5f, 0.0f},
        {-0.5f, -0.5f, 0.0f}
    };

    uint32_t edges[] = {
        0, 1,
        1, 2,
        2, 0
    };

    bool running = true;

    while (running) {
        while (event_poll(&event)) {
            if (event_quit(&event)) {
                running = false;
            }

            if (event_keydown(&event, K_ESCAPE)) {
                running = false;
            }
        }

        window_clear(window, &bg);

        for (uint32_t i = 0; i < 3; i++) {
            vec3_t from = vertices[edges[i * 2]];
            vec3_t to = vertices[edges[i * 2 + 1]];

            from.x = (from.x + 1.0f) * 0.5f * window->width;
            from.y = (-from.y + 1.0f) * 0.5f * window->height;

            to.x = (to.x + 1.0f) * 0.5f * window->width;
            to.y = (-to.y + 1.0f) * 0.5f * window->height;

            window_draw_line(window, from.x, from.y, to.x, to.y, &c_white);
        }

        window_update(window);
    }

    window_destroy(window);

    return 0;
}
