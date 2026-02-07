#ifndef STARLARK_UTF8_H
#define STARLARK_UTF8_H

#include <stdint.h>

// Decode a Unicode code point from a UTF-8 byte stream.
//
// `stream` must be a nonempty, UTF8-encoded string.
// `stream` is advanced past the decoded bytes.
// Returns the decoded Unicode code point.
uint32_t utf8_decode_byte(uint8_t **stream);

#endif
