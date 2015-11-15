#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "fileReader.h"
#include "secretDecoder.h"
#include "dictionary.h"

ArrayList *crackerArrayList;
Dictionary *dictionary;
Dictionary *decodedString;

char *crack(char *encodedMessage, char *keyFilesFolder, char *wordList) {
    crackerArrayList = initCrackerArrayList();
    dictionary = initDictionary();
    readKeyFiles(crackerArrayList, keyFilesFolder);
    fileToDictionary(dictionary, wordList);
    // addWordToDictionary(dictionary, keyFilesFolder);
    int highestScore = 0;
    int highestScoreIndex = 0;
    for (int i = 0; i < crackerArrayList->keyfilesIndex; i++) {
        char *currentKeyfile = crackerArrayList->keyfiles[i];
        printf("cracking with keyfile %s\n", crackerArrayList->keyfilenames[i]);

        int *status = malloc(sizeof(int));
        *status = 0;

        char *currentDecode = decode(currentKeyfile, encodedMessage, status);
        int decodeSize = strlen(currentDecode) + 2;
        free(status);

        char *token;
        char septs[] = " ";
        int score = 0;

        char decodeCopy[decodeSize];
        strncpy(decodeCopy, currentDecode, decodeSize);
        free(currentDecode);
        token = strtok(decodeCopy, septs);

        // if token is not EOF (-1), add it
        while (token != NULL && token[0] != '\0') {
            int exists = wordExistsInDictionary(dictionary, token);
            // printf("%d ", exists);
            if (1 == exists) {
                score += 1;
            }
            token = strtok(NULL, septs);
        }
        if (score > highestScore) {
            highestScore = score;
            highestScoreIndex = i;
        }
        addScoreToCurrentKeyfile(crackerArrayList, score);

    }
    char *result = malloc(sizeof(char) * 100);
    strncpy(result, crackerArrayList->keyfilenames[highestScoreIndex],
            strlen(crackerArrayList->keyfilenames[highestScoreIndex]) + 1);

    freeDictionary(dictionary);
    arrayList_free(crackerArrayList);
    return result;

}
