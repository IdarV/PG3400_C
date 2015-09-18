#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
