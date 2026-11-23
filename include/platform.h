#ifndef PLATFORM_H  // if not defined PLATFORM_H
#define PLATFORM_H  // define it

typedef struct PlatformWindow PlatformWindow;  // declares an opaque structure

// define the event type that the programme recognises (the C compiler assing the number value automatically)
typedef enum {
    PLATFORM_EVENT_QUIT,    // 0 ask for close the window
    PLATFORM_EVENT_RESIZE   // 1 the window has been resise
} PlatformEventType;

// descrive an event, width and height contain the new size for resize events
typedef struct {
    PlatformEventType type;
    int width;
    int height;
} PlatformEvent;

// creates a window, result NULL if creation fails
PlatformWindow *platform_create(
    const char *title,
    int width,
    int height
);

// wait for the next window event and wries it into the caller-provided structure
// result 1 if an event is recived, or -1 on error; the pointer PlatformEvent * is for the provided structure by the caller
int platform_wait_event(
    PlatformWindow *window,
    PlatformEvent *event
);

// displays an RGBA pixel buffer in the window
void platform_present_rgba(
    PlatformWindow *window,
    const unsigned char *pixels,    // points to pixel data
    int width,                      // image width
    int height,                     // image height
    int stride                      // number of byte of a row in memory
);

// releases the window and its backend resources
void platform_destroy(PlatformWindow *window);

#endif
