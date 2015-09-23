#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inspired by http://www.sorting-algorithms.com/merge-sort
void merge_sort(int numbers_length, FileElement *numbers) {
    if (numbers_length > 2) {

        int first_half_size = numbers_length / 2;
        int second_half_size = (numbers_length - first_half_size);

        FileElement *firstHalf = malloc(first_half_size * sizeof(FileElement));
        FileElement *secondHalf = malloc(second_half_size * sizeof(FileElement));

        memcpy(firstHalf, numbers, first_half_size * sizeof(FileElement));
        memcpy(secondHalf, numbers + first_half_size, second_half_size * sizeof(FileElement));
        merge_sort(first_half_size, firstHalf);
        merge_sort(second_half_size, secondHalf);

        int overall_index = 0;
        int first_index = 0;
        int second_index = 0;

        // go through all
        while ((first_index < first_half_size) && (second_index < second_half_size)) {
            if (firstHalf[first_index].value <= secondHalf[second_index].value) {
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

        free(firstHalf);
        free(secondHalf);
    } else if (numbers_length == 2) {
        /**
         * This saves about 11% run-time (in my VM).
         * Since the recursive arrays of size 1 are ignored, the ones of size 2 are the most
         * occurring ones. Because of their size, they are much faster to sort by reference
         * and comparison, rather than sending them through another iteration of merge-sort.
         * I could've optimized this further, and maybe ran a bubble-sort through the smaller
         * sizes, but I decided to keep it simple.
         */
        if (numbers[0].value > numbers[1].value) {
            FileElement temp = numbers[0];
            numbers[0] = numbers[1];
            numbers[1] = temp;
        }
    }
}