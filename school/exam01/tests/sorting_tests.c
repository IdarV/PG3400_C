#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../helpers/FileElement/FileElement.h"
#include "../helpers/Dynarray/dynarray.h"
#include "../helpers/FileElement/FileElement.c"
#include "../sorters/mergesort.c"
#include "../sorters/bubblesort.c"

int main(int argc, char *argv[]){
    FileElement fileElement1;
    FileElement fileElement2;

    FileElement_init(&fileElement1);
    FileElement_init(&fileElement2);

    fileElement1.value = 1;
    fileElement1.original_index = 1;

    fileElement2.value = 2;
    fileElement2.original_index = 2;

    printf("[%d, %d]\n", fileElement1.value, fileElement1.original_index);
    printf("[%d, %d]\n", fileElement2.value, fileElement2.original_index);

    // SWAP

    int temp = fileElement1.value;
    fileElement1.value = fileElement2.value;
    fileElement2.value = temp;


    printf("[%d, %d]\n", fileElement1.value, fileElement1.original_index);
    printf("[%d, %d]\n", fileElement2.value, fileElement2.original_index);

//    const int size = 10000;
//    srand(time(NULL));
//    int integers[size];
//    for(int i = 0; i < size; i++){
//        integers[i] = rand() % 1000000;
//    }
//    merge_sort(size, integers);
//
//    int temp = integers[0];
//    for(int i = 1; i < size; i++){
//        if(temp > integers[i]){
//            printf("ERROR: MERGE SORT DOESNT WORK. (%d:%d > %d:%d\n", (i-1), temp, i, integers[i]);
//            return 1;
//        }
//        if(i == size -1){
//            printf("Merge sort is ok-dokey!\n");
//        }
//        temp = integers[i];
//    }
//    for(int i = 0; i < size; i++){
//        integers[i] = rand() % 1000000;
//    }
//    bubble_sort(size, integers);
//
//    temp = integers[0];
//    for(int i = 1; i < size; i++){
//        if(temp > integers[i]){
//            printf("ERROR: BUBBLE SORT DOESNT WORK. (%d:%d > %d:%d\n", (i-1), temp, i, integers[i]);
//            return 1;
//        }
//        if(i == size -1){
//            printf("Bubble sort is ok-dokey!\n");
//        }
//        temp = integers[i];
//    }
//    return 0;

}