#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int binary_search(int array_length, FileElement *array, int wanted_number) {
    int start = 0;
    int end = array_length;
    int i = 0; //index

    while (start <= end) {
        i = (start + end) / 2;
        if(array[i].value == wanted_number) {
            return i;
        }

        if (array[i].value < wanted_number) {
            start = i + 1;
        } else if (array[i].value > wanted_number) {
            end = i - 1;
        }
    }
    return -1;
}