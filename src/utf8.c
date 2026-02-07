#include "utf8.h"

#include <stdio.h>
#include <stdlib.h>

#include "panic.h"

uint32_t consume_byte(uint8_t **stream) {
    uint8_t c = **stream;
    if (c) {
        (*stream)++;
        return c;
    } else {
        panic("UTF8 error: expected non-null byte");
    }
}

uint32_t consume_continuation_byte(uint8_t **stream) {
    uint8_t c = **stream;

    // The first two bytes must be 10.
    if ((c >> 6) == 2) {
        (*stream)++;
        return c;
    } else {
        panic("UTF8 error: expected continuation byte");
    }
}

uint8_t get_code_point_length(uint8_t c) {
    if ((c >> 7) == 0) {
        return 1;
    }
    // The first three bits must be 110.
    else if ((c >> 5) == 6) {
        return 2;
    }
    // The first four bits must be 1110.
    else if ((c >> 4) == 14) {
        return 3;
    }
    // The first five bites must be 11110.
    else if ((c >> 3) == 30) {
        return 4;
    } else {
        panic("UTF8 error: expected leading byte");
    }
}

// A mask of the first six bits.
#define CONTINUATION_BYTE_MASK 63

#define LEADING_2_BYTE_MASK 31
#define LEADING_3_BYTE_MASK 15
#define LEADING_4_BYTE_MASK 7

uint32_t next_code_point(uint8_t **stream) {
    uint32_t c = consume_byte(stream);
    uint8_t length = get_code_point_length(c);

    if (length == 1) {
        return c;
    } else if (length == 2) {
        uint32_t c2 = consume_continuation_byte(stream);

        return ((c & LEADING_2_BYTE_MASK) << 6) | (c2 & CONTINUATION_BYTE_MASK);
    } else if (length == 3) {
        uint32_t c2 = consume_continuation_byte(stream);
        uint32_t c3 = consume_continuation_byte(stream);

        return ((c & LEADING_3_BYTE_MASK) << 12) |
               ((c2 & CONTINUATION_BYTE_MASK) << 6) |
               (c3 & CONTINUATION_BYTE_MASK);
    } else if (length == 4) {
        uint32_t c2 = consume_continuation_byte(stream);
        uint32_t c3 = consume_continuation_byte(stream);
        uint32_t c4 = consume_continuation_byte(stream);

        return ((c & LEADING_4_BYTE_MASK) << 18) |
               ((c2 & CONTINUATION_BYTE_MASK) << 12) |
               ((c3 & CONTINUATION_BYTE_MASK) << 6) |
               (c4 & CONTINUATION_BYTE_MASK);
    } else {
        panic("UTF8 error: incorrect code point length");
    }
}
