#include "platform.h"

int main(void)
{
    PlatformWindow *window = platform_create("function plot", 900, 800);

    if (window == 0) {
        return 1; // make window fails
    }

    int running = 1;
    int exit_code = 0;

    while (running) {
        PlatformEvent event;

        int result = platform_wait_event(window, &event);

        if (result < 0) {
            exit_code = 2; // Error on read events
            break;
        }

        switch (event.type) {
            case PLATFORM_EVENT_QUIT:
                running = 0;
                break;

            case PLATFORM_EVENT_RESIZE:
                // perora non fa nulla
                break;
        }
    }

    platform_destroy(window);
    return exit_code;
}
