#include <stdio.h>
#include "fileReader.c"



int main(int argc, char *argv[]) {
    char *filename = "hey.txt";
    char *filetext = readFile(filename);

    if (filetext == NULL){
        return -1;
    }

    printf("%s\n", filetext);

    free(filetext);

    return 0;
}