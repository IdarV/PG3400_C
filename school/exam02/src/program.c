#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringHelpers.h"
#include "secretCoder.h"
#include "secretDecoder.h"
#include "secretCoderCracker.h"
#include "arrayList.h"
#include "fileReader.h"
#include "errorHandler.h"
// FGETS

int main(int argc, char *argv[]) {
  ErrorHandler *errorHandler = initErrorHandler();
  char *filename = "../HE2/songLibrary/wakaWaka.txt";
  // char *filename = "../HE2/songLibrary/fireWorkKatyPerry.txt";
  char *secretFile = "../secretMessage.txt";

  char *encodedMessage = encode(filename, secretFile, errorHandler);
  printErrorMessages(errorHandler);

  char *keyFilesFolder = "../HE2/songLibrary";
  char *wordListFile = "/usr/share/dict/words";
  char *result = crack(encodedMessage, keyFilesFolder, wordListFile);
  // printf("%s\n", encodedMessage);
  printf("%s\n", encodedMessage);
  printf("%s\n", result);


  errorHandler_free(errorHandler);
  free(errorHandler);
  free(encodedMessage);
  free(result);

  //    char *wo = "keyFileName\0";
  // char *wordListFile = malloc(sizeof(char) * 80);
  // memcpy(wordListFile, wo, strlen(wo) + 1);
  //
  // char *du = "KeyFileContent\0";
  // char *dubby = malloc(sizeof(char) * 80);
  // memcpy(dubby, du, strlen(du) + 1);
  //
  // ArrayList *arrayList = initArrayList();
  // addKeyFile(arrayList, wordListFile, dubby);
  // printAll(arrayList);
  // arrayList_free(arrayList);
}
