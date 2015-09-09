#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    int height;
    int weight;
} Person;

Person *person_create(char *name, int age, int height, int weight)
{
    Person *who = malloc(sizeof(Person));
    assert(who != NULL);

    char *new_name = malloc(strlen(name));

    who->name = strcpy(new_name, name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void person_print(Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    Person *joe = person_create(
            "Joe Alex", 32, 64, 140);

    Person *frank = person_create(
            "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}