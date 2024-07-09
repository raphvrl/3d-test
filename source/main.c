#include "display/window.h"
#include "display/event.h"

int main(void)
{
    window_t *window = window_init("Hello, World!", 800, 600);
    if (!window) {
        return 1;
    }

    event_t event = event_init();
    color_t bg = C_BLACK;

    bool running = true;

    while (running) {
        while (event_poll(&event)) {
            if (event_quit(&event)) {
                running = false;
            }
        }

        window_clear(window, &bg);
        window_update(window);
    }

    window_destroy(window);

    return 0;
}
