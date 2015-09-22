#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

void Dynarray_init(Dynarray *dynarray){
    dynarray->size = 0;
    dynarray->capacity = 100;

    dynarray->data = malloc(sizeof(int) * dynarray->capacity);
}

void Dynarray_append(Dynarray *dynarray, int value){
    Dynarray_double_capacity_if_full(dynarray);
    dynarray->data[dynarray->size++] = value;
}

int Dynarray_get(Dynarray *dynarray, int index){
    if(index >= dynarray->size || index < 0){
        die("Index %d out of bounds. Array size: %d", index, dynarray->size);
    }
    return dynarray->data[index];
}

void Dynarray_set(Dynarray *dynarray, int index, int value){
    while(index >= dynarray->size){
        Dynarray_append(dynarray, 0);
    }
    dynarray->data[index] = value;
}

void Dynarray_double_capacity(Dynarray *dynarray){
    if(dynarray->size >= dynarray->capacity){
        dynarray->capacity *= 2;
        dynarray->data = realloc(dynarray->data, sizeof(int) * dynarray->capacity);
    }
}

void Dynarray_free(Dynarray *dynarray){
    free(dynarray->data);
}