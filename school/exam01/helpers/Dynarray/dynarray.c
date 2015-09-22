#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

// CREDITS: http://www.happybearsoftware.com/implementing-a-dynamic-array.html

void Dynarray_init(Dynarray *dynarray){
    dynarray->size = 0;
    dynarray->capacity = 100;
    dynarray->data = malloc(sizeof(int) * dynarray->capacity);
    dynarray->original_data = malloc(sizeof(int));
}

void Dynarray_append(Dynarray *dynarray, int value){
    Dynarray_double_capacity_if_full(dynarray);
    dynarray->data[dynarray->size++] = value;
}

int Dynarray_get(Dynarray *dynarray, int index){
    if(index >= dynarray->size || index < 0){
        printf("Index %d out of bounds. Array size: %d", index, dynarray->size);
    }
    return dynarray->data[index];
}

void Dynarray_set(Dynarray *dynarray, int index, int value){
    while(index >= dynarray->size){
        Dynarray_append(dynarray, 0);
    }
    dynarray->data[index] = value;
}

void Dynarray_double_capacity_if_full(Dynarray *dynarray){
    if(dynarray->size >= dynarray->capacity){
        dynarray->capacity *= 2;
        dynarray->data = realloc(dynarray->data, sizeof(int) * dynarray->capacity);
    }
}

void Dynarray_copy_to_original_data(Dynarray *dynarray){
    dynarray->original_data = realloc(dynarray->original_data, sizeof(dynarray->data));
    memcpy(dynarray->original_data, dynarray->data, sizeof(&dynarray->data));
}

void Dynarray_print(Dynarray *dynarray){
    for(int i = 0; i < dynarray->size; i++){
        printf("%d\n", dynarray->data[i]);
    }
}

void Dynarray_free(Dynarray *dynarray){
    free(dynarray->data);
    free(dynarray->original_data);
}