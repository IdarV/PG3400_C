#include "arrayList.h"

ArrayList *initArrayList(){
    //  int score; char *bestmatch;  char **keyfilenames; char **keyfiles;
    ArrayList *arrayList = malloc(sizeof(ArrayList));
    arrayList->keyfilenames = malloc(5 * sizeof(char*));
    arrayList->keyfiles = malloc(5 * sizeof(char*));
    arrayList->score = 0;


    return arrayList;
}


void addKeyFile(ArrayList *arrayList, char *keyFileName, char *keyFileContents){
//    arrayList->keyfiles =
}

void arrayList_free(ArrayList *arrayList){
    free(arrayList->keyfilenames);
    free(arrayList->keyfiles);
    free(arrayList);
}