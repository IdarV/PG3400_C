#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stringHelpers.h"
#include "fileReader.h"
#include <stdio.h>
#include <stdlib.h>

FILE *file = NULL;

char *readKeyFile(char *filename) {
    int size = 1000, pos = 0;
    char *filetext = malloc(sizeof(char) * size);

    if(filetext == NULL){
        printf("Error allocating memory for file contents");
        return NULL;
    }

    char c;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Couldn't open file");
        return NULL;
    }

    while (!feof(file)) {
        //fgetc(file, "%s\n", c);
        c = fgetc(file);

        if(isLetter(&c)){
            if(isHighCase(&c)){
                toLowCase(&c); // #31:17
            }
          filetext[pos++] = c;
        }

        if(pos >= size - 1){
            size *= 2;
            filetext = realloc(filetext, size);

            if(filetext == NULL){
                printf("Error incrementing memory for file conents");
                return NULL;
            }
        }

    }
    // Add a break character so valgrind shuts up
    filetext[pos++] = '\0';

    fclose(file);
    return filetext;
}

char *readFile(char *filename){
    printf("printf");
    int size = 100, pos = 0;
    char *filetext = malloc(sizeof(char) * size);

    if(filetext == NULL){
        printf("Error allocating memory for file contents");
        return NULL;
    }

    char c;
    FILE *thisFile = fopen(filename, "r");
    if (thisFile == NULL) {
        printf("Couldn't open file");
        return NULL;
    }

    while (!feof(thisFile)) {
        c = fgetc(thisFile);

        filetext[pos++] = c;

        if(pos >= size - 1){
            size *= 2;
            filetext = realloc(filetext, size);

            if(filetext == NULL){
                printf("Error incrementing memory for file conents");
                return NULL;
            }
        }

    }
    // Add a break character so valgrind shuts up
    filetext[pos++] = '\0';

    fclose(thisFile);
    return filetext;
}