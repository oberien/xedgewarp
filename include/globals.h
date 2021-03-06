// vim:ts=4:sw=4:expandtab
#pragma once

#include <sys/queue.h>
#include <xcb/xcb.h>
#include "types.h"

/** The Xlib display object. */
extern Display *display;

/** Our gate to the other side. */
extern xcb_connection_t *connection;

/** The root window of this display. */
extern xcb_window_t root;

/** The offset of the RandR extension. */
extern int randr_ext_offset;

/* The major opcode of the XInput2 extension. */
extern int xinput_ext_opcode;

/** The list of RandR outputs. */
extern struct outputs_head outputs;

/* Global configuration. */
extern Config config;

/*
 * We set this whenever a warp has occured so that we
 * prevent further warps until the pointer left the
 * edge at least once.
 */
extern bool has_warped;
