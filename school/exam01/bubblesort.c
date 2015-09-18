#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void print_array(int numbers_length, int *numbers) {
//    for (int i = 0; i < numbers_length; i++) {
//        printf("%d\n", numbers[i]);
//        //if (i != numbers_length - 1) printf(", ");
//    }
//    printf("\n");
//}

void bubble_sort(int numbers_length, int *numbers) {
    for (int j = 0; j < numbers_length; j++) {
        for (int i = numbers_length - 1; i >= j + 1; i--) {
            if (numbers[i] < numbers[i - 1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i - 1];
                numbers[i - 1] = temp;
            }
        }
    }
}

//int main(int argc, char *argv[]) {
//    srand(time(NULL));
//    int numbers[100000];
//    int numbers_length = sizeof(numbers) / sizeof(numbers[1]);
//
//    int range = 100;
//    for(int i = 0; i < numbers_length; ++i)
//    {
//        numbers[i] = rand() % range + 1;
//    }
//
//    print_array(numbers_length, numbers);
//
//    bubble_sort(numbers_length, numbers);
//
//    print_array(numbers_length, numbers);
//
//    printf("HEHE");
//    return 1;
//}
