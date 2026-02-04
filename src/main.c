#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n",
                argc > 0 ? argv[0] : "starlark");
        return 1;
    }

    printf("%s\n", argv[1]);

    return 0;
}
