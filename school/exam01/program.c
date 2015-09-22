#include <string.h>
#include <sys/time.h>
#include "helpers/Dynarray/dynarray.c"
#include "sorters/bubblesort.c"
#include "sorters/mergesort.c"
#include "searchers/binary_search.c"
#include "helpers/filehandler.c"

// CREDS: http://stackoverflow.com/questions/3756323/getting-the-current-time-in-milliseconds
long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // caculate milliseconds
    return milliseconds;
}

void print_array(int numbers_length, int *numbers) {
    for (int i = 0; i < numbers_length; i++) {
        printf("%d\n", numbers[i]);
    }
}

int find_old_index(int array_length, int *array, int number) {
    for (int i = 0; i < array_length; i++) {
        if (array[i] == number) {
            return i;
        }
    }
    return -1;
}

void sort_array(char *sorting_method, int array_size, int *array) {
    if (strcmp(sorting_method, "bubble") == 0) {

        bubble_sort(array_size, array);
    } else if (strcmp(sorting_method, "merge") == 0) {
        merge_sort(array_size, array);
    } else {
        die("Didnt find any sorting argument. \nSorting methods: \"merge\", \"bubble\"\n"
                    "Usage: \"./program [file] [opt: sorting_method] [opt: number_to_search_for]\"");
    }
}

char *set_sort_method(int argc, char *argv[]) {
    if (argc > 2) {
        return argv[2];
    } else {
        return "merge\0";
    }
}

void search_number_interaction(int int_array_size, int *int_array, int *original_array, char *filename) {
    int search_number;
    printf("Number to search for (0 to skip): ");
    scanf("%d", &search_number);

    // do search if fourth argument exists
    if (search_number != 0) {
        // parse second arg to int, and try to get the index of it
        int index = binary_search(int_array_size, int_array, search_number);

        // print results
        if (index == -1) {
            printf("%d is not present in  %s\n", search_number, filename);
        } else {
            for(int i = 0; i < int_array_size; i++){
                printf("OLD: %d\n", original_array[i]);
            }
            int original_index = find_old_index(int_array_size, original_array, search_number);
            printf("index of %d in sorted array is %d (used to be index %d)\n", search_number, index, original_index);
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        // kill program if no file is
        die("Didn't find any file argument. \n"
                    "Usage: \"./program [file] [opt: sorting_method]\"\n");
    }

    // open the file, and count the integers
    open_file(argv[1]);
    //int int_array_size = get_file_integer_count();

    Dynarray numbers;
    Dynarray_init(&numbers);
    ints_to_array(&numbers);

    char *sorting_method = set_sort_method(argc, argv);

    // sort array and record execution time
    long timestart = 0;
    timestart = current_timestamp();

    sort_array(sorting_method, numbers.size, numbers.data);

    long timestop = current_timestamp();

    // print sorted array and execution time
    Dynarray_print(&numbers);
    printf("(sorting with %s took %ld ms.)\n\n", sorting_method, (timestop - timestart));

    // TODO: FIX THIS
    search_number_interaction(numbers.size, numbers.data, numbers.original_data, argv[1]);
    fclose(file);
    Dynarray_free(&numbers);

    return 0;
}