#include "fileEncoder.h"
#include "fileReader.h"
#include <string.h>

bool isInRange(int start, int end, int n) {
    for (int i = start; i <= end; i++) {
        if (n == i) {
            return true;
        }
    }
    return false;
}

// d is distance
int findNextIndex(char c, char *keyFile, int lastIndex, int d) {
    int index = 0;
    char currentChar = 0;
    do {
        currentChar = keyFile[index];
        // if currentchar and currenchar is out of range of the last char
        if (currentChar == c && !isInRange(lastIndex - d, lastIndex + d, index)) {
            return index;
        }
        index++;
    } while ('\0' != currentChar);

    return 0;
}

// default 2
char *encode(char *keyFile, char *secretMessage) {
    return encodeWithDistance(keyFile, secretMessage, 2);
}

char *encodeWithDistance(char *keyFile, char *secretMessage, int d) {
    int size = 1000; // Initial size of encoded message
    int firstSave = 0; // Check if we have saved a string yet. This is important later
    int lastIndex = 0; // Last used key-index
    char *encodedMessage = malloc(sizeof(char) * size); // Encoded message
    char c; // Current char

    if (NULL == encodedMessage) {
        printf("error allocating memory for encoded message\n");
        return NULL;
    }
    char *keyfile = readFile(keyFile); // Open keyfile

    if (NULL == keyfile) {
        printf("error allocating memory for keyfile\n");
        return NULL;
    }

    FILE *file = NULL; // Open secret message
    file = fopen(secretMessage, "r");
    if (file == NULL) {
        printf("Couldn't open file\n");
        return NULL;
    }
    // While we haven't read to the end of the file
    while (!feof(file)) {
        // Get next char
        c = fgetc(file);
        // Longest int64 is 19 characters + two brackets + minus sign + escape character = 23
        char currentString[23];
        // If the charater is letter or a space
        if (isLetter(&c) || c == 32) {
            int i = 0;
            // Just add a space if character is space
            if (c == 32) {
                sprintf(currentString, " ");
            }
                // Add a minus sign and search for lowcase of current number
            else if (isHighCase(&c)) {
                i = findNextIndex(c + 32, keyfile, lastIndex, d);
                sprintf(currentString, "[-%d]", i);
            }
                // Print next lowcase of current number
            else {
                i = findNextIndex(c, keyfile, lastIndex, d);
                sprintf(currentString, "[%d]", i);
            }
            lastIndex = i;

            if (currentString != NULL) {
                if (firstSave == 0) {
                    // Cudos til Fredrick
                    strncpy(encodedMessage, currentString, (strlen(currentString)) + 1);
                    firstSave++;
                } else {

                    char *dest = strncat(encodedMessage, currentString, (strlen(currentString)) + 1); /// sizeof(char)
                    if (dest == NULL) {
                        printf("error writing to encoded file");
                        return NULL;
                    }
                }
            }
        }
    }
    free(keyfile);
    fclose(file);
    return encodedMessage;
}

