#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringHelpers.h"
#include "secretCoder.h"
#include "secretDecoder.h"
#include "secretCoderCracker.h"
#include "fileReader.h"
#include "errorHandler.h"
// FGETS

int main(int argc, char *argv[]) {
// char *encodedMessage, char *keyFilesFolder, char *wordListFile){
    char *encodedMessage = "";
    char *keyFilesFolder = "../HE2/songLibrary";
    char *wordListFile = "/usr/share/dict/words";

    crack(encodedMessage, keyFilesFolder, wordListFile);
//    char *filename = "../hey.txt";
//    char *secretFile = "../secretMessage.txt";
//    if(0 == strcmp(argv[1], "crack")){
//        printf("clarck!\n");
//    }
//    ErrorHandler *errorHandler = initErrorHandler();
//    char *filename = "../hey.txt";
//    char *secretFile = "../secretMessage.txt";
//
//    char *filetext = encode(filename, secretFile, errorHandler);
//    printErrorMessages(errorHandler);
//
//    if (filetext == NULL) {
//        return -1;
//    }
//
//    char *supersecret = decode(filename, filetext);
//
//    if (supersecret == NULL) {
//        return -1;
//    }
//
//    printf("%s\n", filetext);
//    printf("%s\n", supersecret);
//
//    free(filetext);
//    free(supersecret);
//    free(errorHandler->errorMessages);
//    free(errorHandler);
//
//    return 0;
}