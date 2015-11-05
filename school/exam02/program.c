#include <stdio.h>
#include "fileReader.c"
#include "fileEncoder.c"

int main(int argc, char *argv[]) {
//    char *filename = "hey.txt";
//    char *filetext = readFile(filename);
//
//    if (filetext == NULL){
//        return -1;
//    }
//
//    printf("%s\n", filetext);
//
//    free(filetext);

    char *filename = "hey.txt";
    char *secretFile = "secretMessage.txt";
    char *filetext = encode(filename, secretFile);

    if (filetext == NULL){
        return -1;
    }
    printf("filetext:\n");
    printf("%s\n", filetext);

    free(filetext);

    return 0;
}