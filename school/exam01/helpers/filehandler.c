#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

FILE *file = NULL;

void die(const char *message) {
    if (errno) {
        // If errno is set, print the error
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void open_file(char *filename) {
    file = fopen(filename, "r");
    if (file == NULL) {
        die("Couldn't open file.");
    }
}

/**
 * Counts all integers in file
 */
int get_file_integer_count() {
    int i = 0, c = 0;
    while (!feof(file)) {
        fscanf(file, "%d", &i);
        c++;
    }
    rewind(file);

    return c;
}

/**
 * adds integers from file to array. Array should be preset to have fixed size for this
 */
void ints_to_array(Dynarray *dynarray) {
    int i = 0;
    while (!feof(file)) {
        fscanf(file, "%d", &i);
        Dynarray_append(dynarray, i);
    }
    Dynarray_copy_to_original_data(dynarray);

    rewind(file);
}