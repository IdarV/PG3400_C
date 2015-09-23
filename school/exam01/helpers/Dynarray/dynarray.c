#include <stdio.h>
#include <stdlib.h>
#include "../FileElement/FileElement.c"

// CREDITS: http://www.happybearsoftware.com/implementing-a-dynamic-array.html

void Dynarray_init(Dynarray *dynarray){
    dynarray->size = 0;
    dynarray->capacity = 100;
    dynarray->data = malloc(sizeof(FileElement) * dynarray->capacity);
}

void Dynarray_append(Dynarray *dynarray, int value){
    Dynarray_double_capacity_if_full(dynarray);

    FileElement fileElement;
    FileElement_init(&fileElement);
    fileElement.value = value;

    dynarray->data[dynarray->size++] = fileElement;
    printf("VALUE OF FILEELMENT IS %d", dynarray->data[dynarray->size-1].value);
}

void Dynarray_append_with_index(Dynarray *dynarray, int value, int index){
    Dynarray_double_capacity_if_full(dynarray);
    dynarray->data[dynarray->size].value = value;
    dynarray->data[dynarray->size].original_index = index;
    printf("Adding FileElement[%d, %d]\n", value, index);
    dynarray->size++;
}

int Dynarray_get(Dynarray *dynarray, int index){
    if(index >= dynarray->size || index < 0){
        printf("Index %d out of bounds. Array size: %d", index, dynarray->size);
    }
    return dynarray->data[index].value;
}

void Dynarray_double_capacity_if_full(Dynarray *dynarray){
    if(dynarray->size >= dynarray->capacity){
        dynarray->capacity *= 2;
        dynarray->data = realloc(dynarray->data, sizeof(int) * dynarray->capacity);
    }
}

void Dynarray_print(Dynarray *dynarray){
    for(int i = 0; i < dynarray->size; i++){
        printf("%d\n", dynarray->data[i].value);
    }
}

void Dynarray_print_with_index(Dynarray *dynarray){
    for(int i = 0; i < dynarray->size; i++){
        printf("[%d, %d]\n", dynarray->data[i].value, dynarray->data[i].original_index);
    }
}

void Dynarray_free(Dynarray *dynarray){
    free(dynarray->data);
}