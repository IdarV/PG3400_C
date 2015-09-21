#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <tgmath.h>
#include "sorters/bubblesort.c"
#include "sorters/mergesort.c"
#include "helpers/filehandler.c"
#include "searchers/binary_search.c"

long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // caculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

void print_array(int numbers_length, int *numbers) {
    for (int i = 0; i < numbers_length; i++) {
        printf("%d\n", numbers[i]);
    }
    printf("\n");
}

int find_old_index(int array_length, int *array, int number) {
    for (int i = 0; i < array_length; i++) {
        if (array[i] == number) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // kill program if no file is
        die("Didn't find any file argument. \nUsage: \"./program [file] [sorting_method] [opt: number_to_search_for]\"\n");
    }

    // open the file, and count the integers
    open_file(argv[1]);
    int int_array_size = get_file_integer_count();

    // create array with content from files
    int int_array[int_array_size];
    ints_to_array(int_array);

    // copy the newly created array to 'original_array'
    int original_array[int_array_size];
    memcpy(original_array, int_array, sizeof(int_array));

    char *sorting_method = argv[2];
    long timestart = 0;

    // sort based on input
    timestart = current_timestamp();
    if (strcmp(sorting_method, "bubble") == 0) {

        bubble_sort(int_array_size, int_array);
    } else if (strcmp(sorting_method, "merge") == 0) {
        merge_sort(int_array_size, int_array);
    } else {
        die("Didnt find any sorting argument. \nSorting methods: \"merge\", \"bubble\"\nUsage: \"./program [file] [sorting_method] [opt: number_to_search_for]\"");
    }
    long timestop = current_timestamp();
    print_array(int_array_size, int_array);
    printf("sorting took %ld ms.\n", (timestop - timestart));

    if (argc == 4) {
        // parse second arg to int, and try to get the index of it
        int wanted_nr = atoi(argv[3]);
        int index = binary_search(int_array_size, int_array, wanted_nr);

        // print results
        if (index == -1) {
            printf("%d is not present in  %s\n", wanted_nr, argv[1]);
        } else {
            int original_index = find_old_index(int_array_size, original_array, wanted_nr);
            printf("index of %d in sorted array is %d (used to be index %d)\n", wanted_nr, index, original_index);
        }
    }
    fclose(file);

    return 0;
}