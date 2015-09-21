#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../sorters/mergesort.c"
#include "../sorters/bubblesort.c"

int main(int argc, char *argv[]){
    const int size = 10000;
    srand(time(NULL));
    int integers[size];
    for(int i = 0; i < size; i++){
        integers[i] = rand() % 1000000;
    }
    merge_sort(size, integers);

    int temp = integers[0];
    for(int i = 1; i < size; i++){
        if(temp > integers[i]){
            printf("ERROR: MERGE SORT DOESNT WORK. (%d:%d > %d:%d\n", (i-1), temp, i, integers[i]);
            return 1;
        }
        if(i == size -1){
            printf("Merge sort is ok-dokey!\n");
        }
        temp = integers[i];
    }
    for(int i = 0; i < size; i++){
        integers[i] = rand() % 1000000;
    }
    bubble_sort(size, integers);

    temp = integers[0];
    for(int i = 1; i < size; i++){
        if(temp > integers[i]){
            printf("ERROR: BUBBLE SORT DOESNT WORK. (%d:%d > %d:%d\n", (i-1), temp, i, integers[i]);
            return 1;
        }
        if(i == size -1){
            printf("Bubble sort is ok-dokey!\n");
        }
        temp = integers[i];
    }
    return 0;

}