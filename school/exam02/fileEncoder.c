#include "fileReader.h"
#include <string.h>

int findNextIndex(char c, char *keyFile) {
    int index = 1;
    char currentChar = keyFile[index++];
    do {
        currentChar = keyFile[index];
        if (currentChar == c) {
            return index;
        }
        index++;
    } while ('\0' != currentChar);

    return 0;
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
        char currentIndex[16];
        // If the charater is letter or a space, and is not a break character
        if ((isLetter(&c) || c == 32) && c != '\0') {
            int i = 0;
            if(c == 32){
                sprintf(currentIndex, " ");
            }
            else if (isHighCase(&c)) {
                i = findNextIndex(c + 32, keyfile);
                sprintf(currentIndex, "[-%d]", i);
            } else{
                i = findNextIndex(c, keyfile);
                sprintf(currentIndex, "[%d]", i);
            }
            strncat(encodedMessage, currentIndex, 10);
//            printf("%c = %d\n", c, i);
//            sprintf(currentIndex, "[%d]", i);
        }
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

