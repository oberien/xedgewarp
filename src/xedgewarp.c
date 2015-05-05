// vim:ts=4:sw=4:expandtab

#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <xcb/xcb.h>
#include <xcb/xcb_aux.h>
#include "randr.h"
#include "types.h"
#include "globals.h"

xcb_connection_t *connection;
xcb_window_t root;

static void initialize(void) {
    int display;
    connection = xcb_connect(NULL, &display);
    if (xcb_connection_has_error(connection)) {
        errx(EXIT_FAILURE, "could not connect to the X server, bailing out.");
    }

    xcb_screen_t *screen = xcb_aux_get_screen(connection, display);
    root = screen->root;
}

int main(void) {
    initialize();
    xcb_disconnect(connection);
    exit(EXIT_SUCCESS);
}
