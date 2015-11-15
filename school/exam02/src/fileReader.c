#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "stringHelpers.h"
#include "fileReader.h"
#include "arrayList.h"

// Reads a keyfile, returns it [A-Za-z]
char *readKeyFile(char *filename) {
    FILE *file = NULL;

    int size = 1000, pos = 0;
    // Allocate space for file text
    char *filetext = malloc(sizeof(char) * size);

    if (filetext == NULL) {
        printf("Error allocating memory for file contents");
        return NULL;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Couldn't open file");
        return NULL;
    }

    char c;
    // Read file while we havent reached end of file
    while (!feof(file)) {
        // Get next character from file
        c = fgetc(file);

        // If character is letter, add it
        if (isLetter(&c)) {
            // If character is highcase, lowcase it
            if (isHighCase(&c)) {
                toLowCase(&c); // #31:17
            }
            filetext[pos++] = c;
        }

        // Realloc more space if necessary
        if (pos >= size - 1) {
            size *= 2;
            filetext = realloc(filetext, sizeof(char) * size);

            if (filetext == NULL) {
                printf("Error incrementing memory for file conents");
                return NULL;
            }
        }

    }
    // Add a break character to end of string
    filetext[pos++] = '\0';

    fclose(file);
    return filetext;
}

// Reads a text file and returns charray of file contents
char *readFile(char *filename) {
    int size = 100, pos = 0;
    // Allocate space for file text
    char *filetext = malloc(sizeof(char) * size);

    if (filetext == NULL) {
        printf("Error allocating memory for file contents");
        return NULL;
    }

    FILE *thisFile = fopen(filename, "r");
    if (thisFile == NULL) {
        printf("Couldn't open file");
        return NULL;
    }

    char c;
    // Read file while we havent reached end of file
    while (!feof(thisFile)) {
        // Get next character and add it to file
        c = fgetc(thisFile);
        if (c != EOF) {
            filetext[pos++] = c;
        }
        // Reallocate if we need more space
        if (pos >= size - 1) {
            size *= 2;
            filetext = realloc(filetext, size);

            if (filetext == NULL) {
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

// Read all keyfiles in folder into an ArrayList
void readKeyFiles(ArrayList *arrayList, char *keyFilesFolder) {
    DIR *dir;
    struct dirent *ent;

    // Open keyfiles folder
    dir = opendir(keyFilesFolder);

    if (NULL == dir) {
        printf("ERROR: Could not open folder %s\n", keyFilesFolder);
    } else {

        // While we still have more files in directory
        while ((ent = readdir(dir)) != NULL) {
            // And those files is not [..] or [.] (unix file-system files)
            if (0 != strcmp(ent->d_name, "..") && 0 != strcmp(ent->d_name, ".")) {
                // Allocate space for file-name
                char *filename = malloc(sizeof(char) * 100);

                // Add make filename [folder]/[filename]
                strncpy(filename, keyFilesFolder, strlen(keyFilesFolder) + 1);
                strncat(filename, "/\0", (sizeof(char) * 3));
                strncat(filename, ent->d_name, (strlen(ent->d_name)) + 1);
                strncat(filename, "\0", (sizeof(char) * 1));

                // Read keyfile contents
                char *fileContents = readKeyFile(filename);
                // Add keyfile and contents to ArrayList
                addKeyFile(arrayList, filename, fileContents);
            }
        }
    }
    closedir(dir);
}
