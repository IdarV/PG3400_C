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
  if(argc > 3){
    char *arg = argv[1];
    if(strcmp(arg, "encode") == 0){
      //./program encode ../secretMessage.txt ../HE2/songLibrary/wakaWaka.txt
      char *secretMessageFile = argv[2];
      char *keyfile = argv[3];
      char *encodedMessage = encode(keyfile, secretMessageFile, errorHandler);
      printf("Encoded message:\n%s\n", encodedMessage);

      free(encodedMessage);
    }
    else if(strcmp(arg, "decode") == 0){
      // ./program decode ../encodedMessage.txt ../HE2/songLibrary/wakaWaka.txt
      char *secretMessageFile = argv[2];
      char *secretMessage = readFile(secretMessageFile);
      char *keyfile = readKeyFile(argv[3]);
      char *decodedMessage = decode(keyfile, secretMessage);

      printf("Decoded message:\n%s", decodedMessage);

      free(decodedMessage);
      free(secretMessage);
    }
    else if(strcmp(arg, "crack") == 0){
      char *encodedMessageFile = argv[2];
      char *encodedMessage = readFile(encodedMessageFile);
      char *keyFilesFolder = argv[3];
      char *wordsListFile = "/usr/share/dict/words";

      char *result = crack(encodedMessage, keyFilesFolder, wordsListFile);
      printf("%s\n", result);
      free(encodedMessage);
      free(result);
    }
  }
  errorHandler_free(errorHandler);
  free(errorHandler);

  // char *filename = "../HE2/songLibrary/wakaWaka.txt";
  // // char *filename = "../HE2/songLibrary/fireWorkKatyPerry.txt";
  // char *secretFile = "../secretMessage.txt";
  //
  // char *encodedMessage = encode(filename, secretFile, errorHandler);
  // printErrorMessages(errorHandler);
  //
  // char *keyFilesFolder = "../HE2/songLibrary";
  // char *wordListFile = "/usr/share/dict/words";
  // char *result = crack(encodedMessage, keyFilesFolder, wordListFile);
  // // printf("%s\n", encodedMessage);
  // printf("%s\n", encodedMessage);
  // printf("%s\n", result);
  //
  //
  // errorHandler_free(errorHandler);
  // free(errorHandler);
  // free(encodedMessage);
  // free(result);

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
