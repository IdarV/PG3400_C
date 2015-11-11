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
void addKeyFile(ArrayList *arrayList, char *keyFileName, char *keyFileContents);
#endif
