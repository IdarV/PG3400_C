#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "stringHelpers.h"
#include "secretCoder.h"
#include "fileReader.h"

int *globStatus;

char *encode(char *keyFile, char *secretMessage, int *status) {
    globStatus = status;
    return encodeWithDistance(keyFile, secretMessage, 2);
}

void getLetter(char *c, char *currentString, int *lastIndex, int *d, char *keyfile) {
    int charIndex = 0;

    if (isHighCase(c)) {
        toLowCase(c);
        charIndex = findNextIndex(c, keyfile, lastIndex, d);
        // If charIndex is -1, it wasnt found. Add error and dont encode it
        if (-1 == charIndex) {
            *globStatus = 1;
            sprintf(currentString, "%c", *c);
        }
        else {
            sprintf(currentString, "[-%d]", charIndex);
        }
    }
        // Print next lowcase of current number
    else {
        charIndex = findNextIndex(c, keyfile, lastIndex, d);
        if (-1 == charIndex) {
            *globStatus = 1;
            sprintf(currentString, "%c", *c);
        }
        else {
            sprintf(currentString, "[%d]", charIndex);
        }
    }

    currentString += '\0';
    *lastIndex = charIndex;
}

void addLetter(char *stringToAdd, char *encodedMessage, int *firstSave) {
    if (stringToAdd != NULL) {
        if (firstSave == 0) {
            // If the string is not yet put into memory, it had no escape character to look for. Therefore,
            // copy in the string the first time around. After this is done thje first time,
            // the string can be concatinated on.
            strncpy(encodedMessage, stringToAdd, (strlen(stringToAdd)) + 1);
            firstSave++;
        } else {
            // Concatinate the string on the encoded message.
            char *dest = strncat(encodedMessage, stringToAdd, (strlen(stringToAdd)) + 1);

            if (dest == NULL) {
                *globStatus = 1;
            }
        }
    }
}

// Encodes secret file with keyfile, with at leads 'd' distance between
// encoded chars
char *encodeWithDistance(char *keyFileName, char *secretFileName, int d) {
    int size = 1000; // Initial size of encoded message
    int firstSave = 0; // Check if we have saved a string yet. This is important later
    int lastIndex = 9; // Last used key-index
    char c; // Current char
    int index = 0; // Current index in secret message
    char *encodedMessage = calloc(size, sizeof(char) * size); // Encoded message

    if (NULL == encodedMessage) {
        printf("error allocating memory for encoded message\n");
        return NULL;
    }

    // Open keyfile
    char *keyfile = readKeyFile(keyFileName);

    if (NULL == keyfile) {
        printf("error allocating memory for keyfile\n");
        return NULL;
    }
    // Open secret file
    char *secretfile = readFile(secretFileName);

    if (NULL == secretfile) {
        printf("error allocating memory for secret\n");
        return NULL;
    }

    // Get next char
    c = secretfile[index++];
    do {
        // Holds current string to put in encodedMessage
        char currentString[50] = {};
        // If the character is letter or a space
        getLetter(&c, currentString, &lastIndex, &d, keyfile);
        addLetter(currentString, encodedMessage, &firstSave);

        c = secretfile[index++];
    } while (c != '\0' && c != EOF); // While we haven't read the break character

    // free files we don't need anymore
    free(keyfile);
    free(secretfile);

    return encodedMessage;
}
