#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct{
    int score;
    char *bestmatch;

    int keyfilenamesIndex;
    char **keyfilenames;

    int keyfilesIndex;
    char **keyfiles;
} ArrayList;

ArrayList *initArrayList();
void printAllNames(ArrayList *arrayList);
void printAll(ArrayList *arrayList);
void addKeyFile(ArrayList *arrayList, char *keyFileName, char *keyFileContents);
void reAllocIfNecessary(ArrayList *arrayList);
void arrayList_free(ArrayList *arrayList);
#endif
