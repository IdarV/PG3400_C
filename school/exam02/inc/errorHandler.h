#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

typedef struct{
    int index;
    int errors[10];
//    char *errorMessages[1][50] = {{"Could not encrypt all characters, some are displayed in clear text"}};
    char **errorMessages;
} ErrorHandler;

void addError(ErrorHandler *errors, int errorcode);
void printErrorMessages(ErrorHandler *errorHandler);

ErrorHandler *initErrorHandler();

#endif