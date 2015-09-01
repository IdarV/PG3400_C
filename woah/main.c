#include <stdio.h>

void print_array(int *A, int size){
    printf("[");

    for(int i = 0; i < size; i++){
        printf("%d", A[i]);
        if(i != size - 1){
            printf(", ");
        }
    }
    printf ("]\n");
}

void print_array_mem(int* A, int size){
    int i = 0;
    for(; i < size; i++){
        printf("%x: %d\n", &A[i], A[i]);
    }
}

int main(){
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    printf("Array:\n");
    print_array(A, size);
    printf("\nMemory locations:\n");
    print_array_mem(A, size);
    return 0;
}