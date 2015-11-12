#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include <string.h>
#include "arrayList.h"
#include "secretDecoder.h"

// DIR *dir;
// struct dirent *ent;
ArrayList *arrayList;

char *crack(char *encodedMessage, char *keyFilesFolder, char *wordList) {
    arrayList = initArrayList();

    ReadKeyFiles(arrayList,keyFilesFolder);
    //printAll(arrayList);
    for(int i = 0; i < arrayList->keyfilesIndex; i++){


       char *supersecret = decode(arrayList->keyfilenames[i], encodedMessage);

       if (supersecret == NULL) {
           //return -1;
       }
       else{
         printf("%s: %s\n", arrayList->keyfilenames[i],supersecret);
       }
     }


    arrayList_free(arrayList);
    return keyFilesFolder;

}
