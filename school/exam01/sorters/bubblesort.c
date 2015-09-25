// Standard bubble-sort with smallest-first-implementation
void bubble_sort(Dynarray *dynarray) {
    int numbers_length = dynarray->size;
    FileElement *numbers = dynarray->data;

    for (int j = 0; j < numbers_length; j++) {
        for (int i = numbers_length - 1; i >= j + 1; i--) {
            if (numbers[i].value < numbers[i - 1].value) {
                FileElement temp = numbers[i];
                numbers[i]= numbers[i - 1];
                numbers[i - 1] = temp;
            }
        }
    }
}
