#include "errorHandler.h"
#include <stdlib.h>
#include <stdio.h>

ErrorHandler *initErrorHandler() {
    ErrorHandler *errors = malloc(sizeof(ErrorHandler));
    errors->index = 0;
    for (int i = 0; i < 10; i++) {
        errors->errors[i] = 0;
    }
    char **wordsArray = malloc(3 * sizeof(char *));
    wordsArray[0] = "Couldn't encode one or more characters, some are displayed in clear text. "
            "This may be a result of the program not fulfilling the d-condition, or that the character "
            "didn't exist in the keyfile.\0";
    wordsArray[1] = "There was an error encoding file.\0";
    wordsArray[2] = "hunt\0";
    errors->errorMessages = wordsArray;

    return errors;
}

void printErrorMessages(ErrorHandler *errorHandler) {
    int errorGoneOff = 0;
    for (int i = 0; i < 3; i++) {
        if (errorHandler->errors[i] != 0) {
            if (errorGoneOff == 0) {
                printf("\nWARNING: something went wrong:\n");
                errorGoneOff = 1;
            }
            printf("- %s\n", errorHandler->errorMessages[i]);
        }
    }
    if (errorGoneOff != 0) {
        printf("\n");
    }
}

void errorHandler_free(ErrorHandler *errorHandler){
  free(errorHandler->errorMessages);
}


void addError(ErrorHandler *errors, int errorcode) {
    errors->errors[errors->index++] = errorcode;
}
