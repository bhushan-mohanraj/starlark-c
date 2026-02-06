#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *filename;

    if (argc != 2) {
        filename = "main.star";
    } else {
        filename = argv[1];
    }

    printf("%s\n", filename);

    return 0;
}
