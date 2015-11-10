#include <stdio.h>
#include <stdlib.h>

#include "stringHelpers.h"
#include "secretCoder.h"
#include "secretDecoder.h"
#include "fileReader.h"
#include "errorHandler.h"
// FGETS

int main(int argc, char *argv[]) {
    ErrorHandler *errorHandler = initErrorHandler();
    char *filename = "../hey.txt";
    char *secretFile = "../secretMessage.txt";

    char *filetext = encode(filename, secretFile, errorHandler);
    printErrorMessages(errorHandler);

    if (filetext == NULL) {
        return -1;
    }

    char *supersecret = decode(filename, filetext);

    if (supersecret == NULL) {
        return -1;
    }

//        printf("%s", errorHandler->errorMessages[0]);


    printf("%s\n", filetext);
    printf("%s\n", supersecret);

    free(filetext);
    free(supersecret);
    free(errorHandler->errorMessages);
    free(errorHandler);

    return 0;
}