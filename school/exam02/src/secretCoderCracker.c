#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include <string.h>
#include "arrayList.h"
#include "secretDecoder.h"

// DIR *dir;
// struct dirent *ent;
ArrayList *crackerArrayList;

char *crack(char *encodedMessage, char *keyFilesFolder, char *wordList) {
    crackerArrayList = initCrackerArrayList();

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
    while(token != NULL){
      printf("%s\n", token);
      token = strtok(NULL, septs);
    }




    arrayList_free(crackerArrayList);
    return keyFilesFolder;

}
