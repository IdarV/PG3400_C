#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include <string.h>
#include "arrayList.h"

DIR *dir;
struct dirent *ent;
ArrayList *arrayList;

char *crack(char *encodedMessage, char *keyFilesFolder, char *wordList) {
    arrayList = initArrayList();
    dir = opendir(keyFilesFolder);

    if (NULL == dir) {
        printf("ERROR: Could not open folder %s\n", keyFilesFolder);
        return NULL;
    }

    while ((ent = readdir(dir)) != NULL) {
//        printf ("%s\n", ent->d_name);
        if (0 != strcmp(ent->d_name, "..") && 0 != strcmp(ent->d_name, ".")) {
            char *filename = malloc(sizeof(char) * 100); //[100] = {'\0'};
            //filename = "\0";
            strncpy(filename, keyFilesFolder, strlen(keyFilesFolder) + 1);
            strncat(filename, "/\0", (sizeof(char) * 3));
            strncat(filename, ent->d_name, (sizeof(ent->d_name)) + 1);
            strncat(filename, "\0", (sizeof(char) * 2 + 1));
            printf("filename:%s\n", filename);
//
//
//            printf("h..?");
            // cat ent->d_name;
            // char *filenameMalloc = malloc(sizeof())
            // printf("filename: %s\n", *filename);
            char *fileContents = readKeyFile(filename);
            //char *fileContentsMalloc = malloc(strlen(fileContents) + 1);
            //fileContentsMalloc = fileContents;
            // printf("%s\n------------------------------\n", fileContents);
            addKeyFile(arrayList, filename, fileContents);
        }
    }
    closedir(dir);

    printAll(arrayList);
    arrayList_free(arrayList);
    return keyFilesFolder;

}
