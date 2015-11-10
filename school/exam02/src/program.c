#include <stdio.h>
#include <stdlib.h>

#include "stringHelpers.h"
#include "fileEncoder.h"
#include "fileDecoder.h"
#include "fileReader.h"

//typedef struct{
//    COULD_NOT_DECODE_MATCH_ALL_CHARACTERS;
//} errorcodes;

int main(int argc, char *argv[]) {
    char *filename = "../hey.txt";
    char *secretFile = "../secretMessage.txt";
    int errors[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    char *filetext = encode(filename, secretFile, errors);

    if (filetext == NULL) {
        return -1;
    }

    char *supersecret = decode(filename, filetext);

    if (supersecret == NULL) {
        return -1;
    }

    for(int i = 0; i < 10; i++){
        if(errors[i] != 0){
            printf("WARNING: GOT ERROR %d\n", errors[i]);
        }
    }

    printf("%s\n", filetext);
    printf("%s\n", supersecret);

    free(filetext);
    free(supersecret);

    return 0;
}