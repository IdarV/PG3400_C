#include <stdio.h>
#include <stdlib.h>

FILE *file = NULL;

void open_file(char *filename) {
    file = fopen(filename, "r");
    if (file == NULL) {
        die("Couldn't open file");
    }
}

void close_file() {
    fclose(file);
}


//adds integers from file to array. Array should be 'initialized' and have size
void file_to_array(Dynarray *dynarray) {
    int i = 0;
    int index = 0;
    while (!feof(file)) {
        // Only append if scan if successful
        if (fscanf(file, "%d", &i)) {
            Dynarray_append_with_index(dynarray, i, index++);
        }
    }
    rewind(file);
}