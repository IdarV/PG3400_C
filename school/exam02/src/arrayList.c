#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

// Contains keyfile-names, keyfiles and
ArrayList *initCrackerArrayList(){
    ArrayList *arrayList = malloc(sizeof(ArrayList));

    arrayList->keyfilenamesIndex = 0;
    arrayList->keyfilenames = malloc(5 * sizeof(char*));
    arrayList->keyfilesIndex = 0;
    arrayList->keyfiles = malloc(5 * sizeof(char*));
    arrayList->score = malloc(5 * sizeof(int));

    return arrayList;
}

void addScoreToCurrentKeyfile(ArrayList *arrayList, int score){
  arrayList->score[arrayList->keyfilesIndex] = score;
}

void printAllNames(ArrayList *arrayList){
    for(int i = 0; i < arrayList->keyfilenamesIndex; i++){
        printf("%s\n", arrayList->keyfilenames[i]);
    }
}

void printAll(ArrayList *arrayList){
    for(int i = 0; i < arrayList->keyfilenamesIndex; i++){
        printf("%s: %s\n", arrayList->keyfilenames[i], arrayList->keyfiles[i]);
    }
}


void addKeyFile(ArrayList *arrayList, char *keyFileName, char *keyFileContents){
    reAllocIfNecessary(arrayList);
    arrayList->keyfilenames[arrayList->keyfilenamesIndex++] = keyFileName;
    arrayList->keyfiles[arrayList->keyfilesIndex++] = keyFileContents;
}

void arrayList_free(ArrayList *arrayList){
    for(int i = 0; i < arrayList->keyfilenamesIndex; i++){
        free(arrayList->keyfilenames[i]);
    }

    for(int i = 0; i < arrayList->keyfilesIndex; i++){
        free(arrayList->keyfiles[i]);
    }

    free(arrayList->keyfilenames);
    free(arrayList->keyfiles);
    free(arrayList->score);
    free(arrayList);
}

void reAllocIfNecessary(ArrayList *arrayList){
    // Realloc if next indexes makes each array bigger than we have already allocated.
    if(((arrayList->keyfilenamesIndex + 1) * sizeof(char*))> sizeof(arrayList->keyfilenames)){
        arrayList->keyfilenames = realloc(arrayList->keyfilenames, sizeof(arrayList->keyfilenames) * arrayList->keyfilenamesIndex * 2  );
    }
    if(((arrayList->keyfilesIndex + 1) * sizeof(char*))> sizeof(arrayList->keyfiles)){
        arrayList->keyfiles = realloc(arrayList->keyfiles, sizeof(arrayList->keyfiles) * arrayList->keyfilesIndex *  2);
        arrayList->score = realloc(arrayList->score, sizeof(arrayList->score) * arrayList->keyfilesIndex * 2);
    }
}
