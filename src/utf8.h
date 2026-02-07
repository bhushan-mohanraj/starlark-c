#ifndef STARLARK_UTF8_H
#define STARLARK_UTF8_H

#include <stdint.h>

// Get the next code point.
//
// `stream` must be a nonempty, UTF8-encoded string.
uint32_t next_code_point(char **stream);

#endif
