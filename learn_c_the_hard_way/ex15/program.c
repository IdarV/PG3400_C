#include <stdio.h>
#include <strings.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Create two arrays that we care about
    int ages[] = {23, 43, 12, 89, 2};

    char *names[] = {"Kim", "Idar", "Fredrick", "Tomas", "Hello Kitty"};

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(ages[0]);

    // first way using indexing
    for (int i = 0; i < count; i++) {
        printf("%s har %d years alive.\n", names[i], ages[i]);
    }

    printf("-------\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    for (int i = 0; i < count; i++) {
        printf("%s is %d years old\n", *(cur_name + i), *(cur_age + i));
    }

    printf("-------\n");

    // third way, pointers are just arrays
    for (int i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("-------\n");

    // fourth way with pointers in a stupid complex way
    for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    return 0;
}



