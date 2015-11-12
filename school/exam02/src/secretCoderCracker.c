#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include <string.h>
#include "arrayList.h"
#include "secretDecoder.h"
#include "dictionary.h"

// DIR *dir;
// struct dirent *ent;
ArrayList *crackerArrayList;
Dictionary *dictionary;

char *crack(char *encodedMessage, char *keyFilesFolder, char *wordList) {
    crackerArrayList = initCrackerArrayList();
    dictionary = initDictionary();
    ReadKeyFiles(crackerArrayList,keyFilesFolder);
    char *words = readFile("/usr/share/dict/words");
    int wordsSize = strlen(words) + 1;

    char wordsCopy[wordsSize];
    strncpy(wordsCopy, words, wordsSize);
    free(words);
    // printf("%s\n", wordsCopy);

    char *token;
    char septs[] = "\n";

    token = strtok(wordsCopy, septs);
    printf("dictionary size/capacity before adding: %d / %d\n", dictionary->wordsListIndex, dictionary->wordsListCapacity);

    while(token != NULL){
      // printf("%s\n", token);
      addWordToDictionary(dictionary, token);
      token = strtok(NULL, septs);
    }

    printf("dictionary size/capacity after adding: %d / %d\n", dictionary->wordsListIndex, dictionary->wordsListCapacity);
    printf("HOOo%s\n", dictionary->wordsList[0]);



    freeDictionary(dictionary);
    arrayList_free(crackerArrayList);
    return keyFilesFolder;

}
