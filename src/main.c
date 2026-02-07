#include <stdio.h>
#include <stdlib.h>

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
    char *filename;

    if (argc != 2) {
        filename = "main.star";
    } else {
        filename = argv[1];
    }

    printf("%s\n", filename);

    return 0;
}
