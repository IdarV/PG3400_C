#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

FILE *file = NULL;

/*
 * Kills the program with error message.
 * source: http://c.learncodethehardway.org/book/ex18.html
 */
void die(const char *message) {
    if (errno) {
        // If errno is set, print the error
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

/*
 * Tries to set global FILE
 */
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
 *
 */
void ints_to_array(int *start) {
    int i = 0, c = 0;
    while (!feof(file)) {
        fscanf(file, "%d", &i);
        start[c] = i;
        c++;
    }

    rewind(file);
}

/**
 * Prints file contents
 */
void read_file() {
    int i = 0;

    while (!feof(file)) {
        fscanf(file, "%d", &i);
        printf("%d\n", i);
    }
    printf("\n");
    rewind(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        die("Didn't find any file argument\n");
    }
    char *filename = argv[1];
    open_file(filename);
    int count = get_file_integer_count();

    int int_array[count + 1];
    int_array[count] = '\0';
    ints_to_array(int_array);
    for (int i = 0; int_array[i] != '\0'; i++) {
        printf("%d\n", int_array[i]);
    }


    printf("file integer count is %d\n", count);



    fclose(file);

    return 0;
}