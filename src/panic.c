#include "panic.h"

#include <stdio.h>
#include <stdlib.h>

void panic(char *message) {
    fprintf(stderr, "%s", message);
    fprintf(stderr, "\n");

    exit(1);
}
