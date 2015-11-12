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
    // fileToDictionary(dictionary, wordList);
    addWordToDictionary(dictionary, keyFilesFolder);

    for(int i = 0; i < dictionary->wordsListIndex; i++){
      // printf("%s\n", dictionary->wordsList[i]);
    }



    freeDictionary(dictionary);
    arrayList_free(crackerArrayList);
    return keyFilesFolder;

}
