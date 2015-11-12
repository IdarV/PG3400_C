#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include <string.h>
#include "arrayList.h"
#include "secretDecoder.h"
#include "dictionary.h"

ArrayList *crackerArrayList;
Dictionary *dictionary;
Dictionary *decodedString;

char *crack(char *encodedMessage, char *keyFilesFolder, char *wordList) {
    crackerArrayList = initCrackerArrayList();
    dictionary = initDictionary();
    readKeyFiles(crackerArrayList,keyFilesFolder);
    fileToDictionary(dictionary, wordList);
    // addWordToDictionary(dictionary, keyFilesFolder);

    for(int i = 0; i < crackerArrayList->keyfilesIndex; i++){
      char *currentKeyfile = crackerArrayList->keyfiles[i];
      char *currentDecode = decode(currentKeyfile, encodedMessage);
      int decodeSize = strlen(currentDecode) + 1;

      char *token;
      char septs[] = " ";
      int score = 0;

      // int decodeSize = strlen(currentDecode) + 1;
      char decodeCopy[decodeSize];
      strncpy(decodeCopy, currentDecode, decodeSize);
      token = strtok(decodeCopy, septs);

      // if token is not EOF (-1), add it
      while(token != NULL && token[0] != '\0'){
        int exists = wordExistsInDictionary(dictionary, token);
        printf("%d ", exists);
        if(1 == exists){
          score += 1;
        }
        token = strtok(NULL, septs);
      }
      addScoreToCurrentKeyfile(crackerArrayList, score);
      printf("\n%s : %d\n", currentDecode, score);


    }

    // for(int i = 0; i < dictionary->wordsListIndex; i++){
    // }



    freeDictionary(dictionary);
    arrayList_free(crackerArrayList);
    return keyFilesFolder;

}
