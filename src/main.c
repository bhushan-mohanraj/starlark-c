#include <stdio.h>
#include <stdlib.h>

#include "utf8.h"

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    size_t size = 0;
    while (fgetc(file) != EOF) {
        size++;
    }

    char *content = malloc(size + 1);
    if (!content) {
        fclose(file);
        return NULL;
    }

    rewind(file);
    for (size_t i = 0; i < size; i++) {
        content[i] = fgetc(file);
    }
    content[size] = '\0';

    fclose(file);
    return content;
}

int main(int argc, char **argv) {
    char *filename = argc == 2 ? argv[1] : "examples/test.txt";
    printf("%s\n", filename);

    char *stream = read_file(filename);
    unsigned i = 0;
    while (*stream) {
        printf("%04d %08x\n", i++, utf8_decode_byte((uint8_t **) &stream));
    }

    return 0;
}
