#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stringHelpers.h"
#include "fileReader.h"
#include "arrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

FILE *file = NULL;

char *readKeyFile(char *filename) {
    int size = 1000, pos = 0;
    char *filetext = malloc(sizeof(char) * size);

    if(filetext == NULL){
        printf("Error allocating memory for file contents");
        return NULL;
    }

    char c;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Couldn't open file");
        return NULL;
    }

    while (!feof(file)) {
        //fgetc(file, "%s\n", c);
        c = fgetc(file);

        if(isLetter(&c)){
            if(isHighCase(&c)){
                toLowCase(&c); // #31:17
            }
          filetext[pos++] = c;
        }

        if(pos >= size - 1){
            size *= 2;
            filetext = realloc(filetext, sizeof(char) * size);

            if(filetext == NULL){
                printf("Error incrementing memory for file conents");
                return NULL;
            }
        }

    }
    // Add a break character so valgrind shuts up
    filetext[pos++] = '\0';

    fclose(file);
    return filetext;
}

char *readFile(char *filename){
    int size = 100, pos = 0;
    char *filetext = malloc(sizeof(char) * size);

    if(filetext == NULL){
        printf("Error allocating memory for file contents");
        return NULL;
    }

    char c;
    FILE *thisFile = fopen(filename, "r");
    if (thisFile == NULL) {
        printf("Couldn't open file");
        return NULL;
    }

    while (!feof(thisFile)) {
        c = fgetc(thisFile);

        filetext[pos++] = c;

        if(pos >= size - 1){
            size *= 2;
            filetext = realloc(filetext, size);

            if(filetext == NULL){
                printf("Error incrementing memory for file conents");
                return NULL;
            }
        }

    }
    // Add a break character so valgrind shuts up
    filetext[pos++] = '\0';

    fclose(thisFile);
    return filetext;
}

// char **readFileToList(char *){
//   printf("printf");
//   int size = 100, pos = 0;
//   char **words = malloc(sizeof(char*) * size);
//
//   if(filetext == NULL){
//       printf("Error allocating memory for file contents");
//       return NULL;
//   }
//
//   FILE *thisFile = fopen(filename, "r");
//   if (thisFile == NULL) {
//       printf("Couldn't open file");
//       return NULL;
//   }
//
//   char c;
//   int currentStringSize = 10;
//   while (!feof(thisFile)) {
//     char currentWord*;
//     c = fscanf(thisFile, "%s", currentWord);
//     char *currentWordMalloc = malloc(strlen(currentWord) + 1);
//     memcpy(currentWordMalloc, currentWord);
//   }
//   // Add a break character so valgrind shuts up
//   //filetext[pos++] = '\0';
//
//   fclose(thisFile);
//   return words;
// }

void readKeyFiles(ArrayList *arrayList, char *keyFilesFolder){
  DIR *dir;
  struct dirent *ent;

  dir = opendir(keyFilesFolder);

  if (NULL == dir) {
      printf("ERROR: Could not open folder %s\n", keyFilesFolder);
  } else{

  while ((ent = readdir(dir)) != NULL) {
      if (0 != strcmp(ent->d_name, "..") && 0 != strcmp(ent->d_name, ".")) {
          char *filename = malloc(sizeof(char) * 100); //[100] = {'\0'};
          //filename = "\0";
          strncpy(filename, keyFilesFolder, strlen(keyFilesFolder) + 1);
          strncat(filename, "/\0", (sizeof(char) * 3));
          strncat(filename, ent->d_name, (sizeof(ent->d_name)) + 1);
          strncat(filename, "\0", (sizeof(char) * 1));

          char *fileContents = readKeyFile(filename);
          addKeyFile(arrayList, filename, fileContents);
      }
  }
}
  closedir(dir);
}
