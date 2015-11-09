#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void die(const char *message) {
    if (errno) {
        // If errno is set, print the error
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void sort_array(char *sorting_method, Dynarray *dynarray) {
    if (strcmp(sorting_method, "bubble") == 0) {
        bubble_sort(dynarray);
    }

    else if (strcmp(sorting_method, "merge") == 0) {
        merge_sort(dynarray->size, dynarray->data);
    }

    else {
        die("Didnt find any sorting argument. \nSorting methods: \"merge\", \"bubble\"\n"
                    "Usage: \"./program [file] [opt: sorting_method] [opt: number_to_search_for]\"");
    }
}

void search_number_interaction(Dynarray *dynarray, char *filename) {
    int search_number;
    int cont = 1;

    do {
        printf("Number to search for <0 to exit>: ");
        cont = scanf("%d", &search_number);

        // do search if fourth argument exists
        if (search_number != 0) {
            // parse second arg to int, and try to get the index of it
            int index = binary_search(dynarray, search_number);

            // print results
            if (index == -1) {
                printf("%d is not present in  %s\n", search_number, filename);
            } else {
                printf("index of %d in the sorted array is %d (used to be index %d)\n", search_number, index,
                       dynarray->data[index].original_index);
            }
        } else {
            cont = 0;
        }
    } while (cont);
}

// CREDS: http://stackoverflow.com/questions/3756323/getting-the-current-time-in-milliseconds
long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // caculate milliseconds
    return milliseconds;
}

void print_array_if_told(int argc, char *argv[], Dynarray *dynarray) {
    if (argc >= 4) {
        if (argv[3] != NULL) {
            if (strcmp(argv[3], "loud") == 0) {
                Dynarray_print(dynarray);
            }
        }
    }
}

char *set_sort_method(int argc, char *argv[]) {
    if (argc > 2) {
        return argv[2];
    } else {
        return "merge";
    }
}

