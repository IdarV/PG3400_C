#include "fileReader.h"
#include <string.h>


int findNextIndex(char c, char *keyFile) {
    int index = 0;
    char currentChar = keyFile[index++];
    do {
        currentChar = keyFile[index];
        if (currentChar == c) {
            return index;
        }
        index++;
    } while ('\0' != currentChar);

    return index;
}

char *encode(char *keyFile, char *secretMessage) {
    int size = 1000;
    char *encodedMessage = malloc(sizeof(char) * size);
    if (NULL == encodedMessage) {
        printf("error allocating memory for encoded message\n");
        return NULL;
    }
    char *keyfile = readFile(keyFile);
    if (NULL == keyfile) {
        printf("error allocating memory for keyfile\n");
        return NULL;
    }
    char c;
    FILE *file = NULL;
    file = fopen(secretMessage, "r");
    if (file == NULL) {
        printf("Couldn't open file\n");
        return NULL;
    }
    while (!feof(file)) {
        c = fgetc(file);
        if (isLetter(&c) && c != '\0') {
//        printf("%c", c);
            if (isHighCase(&c)) {

            }
            int i = findNextIndex(c, keyfile);
            printf("%c = %d\n", c, i);
            sprintf(encodedMessage, "[%d]", i);
            //encodedMessage = strncat(encodedMessage, currentMessage, 4);
            if (encodedMessage == NULL) {
                printf("error encoding message\n");
                return NULL;
            }
        }
        size += 3;
        encodedMessage = realloc(encodedMessage, size);

        if (encodedMessage == NULL) {
            printf("Error incrementing memory for file conents\n");
            return NULL;
        }
    }
    free(keyfile);
    fclose(file);
    return encodedMessage;
}

