#include <stdio.h>
#include "dynarray.c"

int main(){
    Dynarray dynarray;
    Dynarray_init(&dynarray);

    for(int i = 0; i < 800; i++){
        Dynarray_append(&dynarray, i);
    }

    Dynarray_print(&dynarray);
    printf("Dynarray capacity: %d\nSize: %d\n", dynarray.capacity, dynarray.size);

    Dynarray_append(&dynarray, 3782);

    Dynarray_free(&dynarray);
    printf("Dynarray capacity: %d\nSize: %d\n", dynarray.capacity, dynarray.size);
}
