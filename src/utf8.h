#ifndef STARLARK_UTF8_H
#define STARLARK_UTF8_H

#include <stdint.h>

uint32_t next_code_point(char **stream);

#endif
