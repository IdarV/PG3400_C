#include <stdio.h>
#include "helpers/bubblesort.c"
#include "helpers/filehandler.c"
#include "helpers/binary_search.c"

void print_array(int numbers_length, int *numbers) {
    for (int i = 0; i < numbers_length; i++) {
        printf("%d\n", numbers[i]);
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

    if(argc == 3){
        int wanted_nr = atoi(argv[2]);
        int index = binary_search(count,int_array, wanted_nr);
        printf("index of %d is %d\n", wanted_nr, index);
    }

    fclose(file);

    return 0;
}