#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fileReader.h"

FILE *file = NULL;

bool isLetter(char *c){
    return (*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z');
}

bool isHighCase(char *c){
    return *c <= 90;
}

void toLowCase(char *c){
    *c = *c + 32;
}

char *readFile(char *filename) {
    int size = 1000, pos = 0;
    char *filetext = malloc(sizeof(char) * size);
    char c = NULL;
    file = fopen(filename, "r");
    while (!feof(file)) {
        if (file == NULL) {
            printf("file is null\n");
        }
        //fgetc(file, "%s\n", c);
        c = fgetc(file);

        if(isLetter(&c)){
            if(isHighCase(&c)){
                toLowCase(&c);
            }
          filetext[pos++] = c;
        }

        if(pos >= size - 1){
            size *= 2;
            filetext = realloc(filetext, size);
        }

    }
    fclose(file);
    return filetext;
}