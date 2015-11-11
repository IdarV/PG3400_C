#include <dirent.h>
#include <stdio.h>
#include "fileReader.h"
#include <string.h>

DIR *dir;
struct dirent *ent;


char *crack(char *encodedMessage, char *keyFilesFolder, char *wordList) {
    dir = opendir(keyFilesFolder);

    if (NULL == dir) {
        printf("ERROR: Could not open folder %s\n", keyFilesFolder);
        return NULL;
    }

    while ((ent = readdir(dir)) != NULL) {
//        printf ("%s\n", ent->d_name);
        if (0 != strcmp(ent->d_name, "..") && 0 != strcmp(ent->d_name, ".")) {
            char filename[100] = {'\0'};
            strcpy(filename, keyFilesFolder);
            strncat(filename, "/\0", (sizeof(char) * 2 + 1));
            strncat(filename, ent->d_name, (sizeof(ent->d_name)) + 1);
            strncat(filename, "\0", (sizeof(char) * 2 + 1));
//        printf("filename:%s\n", filename);
//
//
//            printf("h..?");
            // cat ent->d_name;
            printf("filename: %s\n", filename);
            char *fileContents = readKeyFile(filename);
            printf("%s\n------------------------------\n", fileContents);
        }
    }
    closedir(dir);
    return "ehwe";

}