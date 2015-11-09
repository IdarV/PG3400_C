#include <stdio.h>
#include <stdlib.h>

#include "stringHelpers.h"
#include "fileEncoder.h"
#include "fileDecoder.h"
#include "fileReader.h"

int main(int argc, char *argv[]) {
    char *filename = "../beatItMJ.txt";
    char *secretFile = "../secretMessage.txt";
    char *filetext = encode(filename, secretFile);

    if (filetext == NULL) {
        return -1;
    }

    char *supersecret = decode(filename, filetext);

    if (supersecret == NULL) {
        return -1;
    }

    printf("%s\n", filetext);
    printf("%s\n", supersecret);

    free(filetext);
    free(supersecret);

    return 0;
}