#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "bubblesort.c"

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
 * Tries to set global file
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
 * adds integers from file to array. Array should be preset to have fixed size for this
 */
void ints_to_array(int *array) {
    int i = 0, c = 0;
    while (!feof(file)) {
        fscanf(file, "%d", &i);
        array[c] = i;
        c++;
    }

    rewind(file);
}

void print_array(int numbers_length, int *numbers) {
    for (int i = 0; i < numbers_length; i++) {
        printf("%d\n", numbers[i]);
        //if (i != numbers_length - 1) printf(", ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        die("Didn't find any file argument\n");
    }

    // open file, and count contents
    char *filename = argv[1];
    open_file(filename);
    int count = get_file_integer_count();

    // create array with size of contents, set break as last
    int int_array[count];
    ints_to_array(int_array);

    bubble_sort(count, int_array);
    print_array(count, int_array);

    printf("file integer count is %d\n", count);

    fclose(file);

    return 0;
}