#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inspired by http://www.sorting-algorithms.com/merge-sort
void mergesort(int numbers_length, int *numbers) {
    if (numbers_length > 2) {

        int first_half_size = numbers_length / 2;
        int second_half_size = (numbers_length - first_half_size);

        int *firstHalf = malloc(first_half_size * sizeof(int));
//    if (!firstHalf) {
//        /* handle error */
//    }

        int *secondHalf = malloc(second_half_size * sizeof(int));
//    if (!secondHalf) {
//        /* handle error */
//    }

        memcpy(firstHalf, numbers, first_half_size * sizeof(int));
        memcpy(secondHalf, numbers + first_half_size, second_half_size * sizeof(int));
        mergesort(first_half_size, firstHalf);
        mergesort(second_half_size, secondHalf);

        int overall_index = 0;
        int first_index = 0;
        int second_index = 0;

        // go through all
        while ((first_index < first_half_size) && (second_index < second_half_size)) {
            if (firstHalf[first_index] >= secondHalf[second_index]) {
                numbers[overall_index] = firstHalf[first_index];
                first_index++;
            } else {
                numbers[overall_index] = secondHalf[second_index];
                second_index++;
            }
            overall_index++;
        }
        while (first_index < first_half_size) {
            numbers[overall_index] = firstHalf[first_index];
            first_index++;
            overall_index++;
        }

        while (second_index < second_half_size) {
            numbers[overall_index] = secondHalf[second_index];
            second_index++;
            overall_index++;
        }
    } else if (numbers_length == 2) {
        if (numbers[0] < numbers[1]) {
            int temp = numbers[0];
            numbers[0] = numbers[1];
            numbers[1] = temp;
        }
    }


}

int main(int argc, char *argv[]) {
    int numbers[] = {43, 43, 3, 5, 1, 12, 43};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    printf("\nBefore sort:\n");
    for (int i = 0; i < length; i++) {
        printf("%d, ", numbers[i]);
    }
    printf("\n\n");

    mergesort(length, numbers);

    printf("RESULT:\n");
    for (int i = 0; i < length; i++) {
        printf("%d, ", numbers[i]);
    }
    printf("\n");
}