#include <stdio.h>
#include <stdlib.h>
#include "../helpers/FileElement/FileElement.h"
#include "../helpers/Dynarray/dynarray.h"
#include "../sorters/sorters.h"

#include "../helpers/FileElement/FileElement.c"
#include "../sorters/mergesort.c"
#include "../sorters/bubblesort.c"

void test_sorting_with(char *method);

int main(int argc, char *argv[]){
    test_sorting_with("merge");
    test_sorting_with("bubble");
}

void test_sorting_with(char *method){
    int number_of_files = 1000;
    FileElement file_element_array[number_of_files];
    for(int i = 0; i < 1000; i++){
        FileElement fileElement;
        FileElement_init(&fileElement);
        fileElement.value = i;
        fileElement.original_index = number_of_files - 1 - i;
        file_element_array[number_of_files - 1 - i] = fileElement;
    }

    if(strcmp(method, "merge")){
        merge_sort(number_of_files, file_element_array);
    } else if(strcmp(method, "bubble")){
        bubble_sort(number_of_files, file_element_array);
    }

    FileElement last = file_element_array[0];

    for(int i = 0; i < number_of_files; i++){
        if(file_element_array[i].value < last.value){
            printf("\033[31mTest failed, %s_sort did not sort \033[0m\n", method);
            exit(1);
        }
        last = file_element_array[i];
    }
    printf("\033[32m%s_sort: Ok!\033[0m\n", method);
}