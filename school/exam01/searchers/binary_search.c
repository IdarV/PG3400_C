#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int binary_search(Dynarray array, int wanted_number) {
    int start = 0;
    int end = array.size;
    int i = 0; //index

    while (start <= end) {
        i = (start + end) / 2;
        int data = array.data[i].value;
        if(data == wanted_number) {
            return i;
        }

        if (data < wanted_number) {
            start = i + 1;
        } else if (data > wanted_number) {
            end = i - 1;
        }
    }
    return -1;
}