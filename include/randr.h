// vim:ts=4:sw=4:expandtab
#pragma once

#include <xcb/xcb.h>
#include <xcb/randr.h>
#include "types.h"

/**
 * Query RandR outputs.
 *
 */
void randr_query_outputs(void);

/**
 * Returns the output that contains this position.
 * Returns NULL if the position is not on any output.
 */
Output *randr_get_output_containing(position_t pointer);

/**
 * Returns the next output in the given direction relative to the specified
 * output. Returns NULL if no such output exists.
 * The given pointer must lie within the given output.
 */
Output *randr_next_output_in_direction(Output *from, position_t pointer, direction_t direction);

/**
 * Returns the next output in the given direction assuming the outputs
 * to form a torus shape, i.e., it will actually look on the far opposite side
 * of the given direction.
 */
Output *randr_cycle_output_in_direction(position_t pointer, direction_t direction);
