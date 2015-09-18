#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int binary_search(int array_length, int *array, int wanted_number) {
    int start = 0;
    int end = array_length;
    int i = 0; //index

    while (start <= end) {
        i = (start + end) / 2;
//        printf("start: %d, end: %d, i: %d, array[i]:%d, wanted: %d\n", start, end, i, array[i], wanted_number);
//        sleep(1);
        if(array[i] == wanted_number) {
            return i;
        }

        if (array[i] < wanted_number) {
            start = i + 1;
        } else if (array[i] > wanted_number) {
            end = i - 1;
        }
    }

    return -1;
}


//int main(int argc, char *argv[]) {
//    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//    int array_length = sizeof(array) / sizeof(array[0]);
//
//    for (int i = 9; i < array_length; i++) {
//
//        int j = binary_search(array_length, array, i);
//        printf("%d index: %d\n", i, j);
//    }
//
////    int j = get_index(array_length, array, 1);
////    printf("%d index\n",j);
//
//    return 1;
//}