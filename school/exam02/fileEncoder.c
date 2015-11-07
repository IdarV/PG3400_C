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

// default d = 2
char *encode(char *keyFile, char *secretMessage) {
    return encodeWithDistance(keyFile, secretMessage, 2);
}

char *encodeWithDistance(char *keyFileName, char *secretFileName, int d) {
    int size = 1000; // Initial size of encoded message
    int firstSave = 0; // Check if we have saved a string yet. This is important later
    int lastIndex = 0; // Last used key-index
    char c; // Current char
    int index = 0; // Current index in secret message
    char *encodedMessage = malloc(sizeof(char) * size); // Encoded message

    if (NULL == encodedMessage) {
        printf("error allocating memory for encoded message\n");
        return NULL;
    }
    char *keyfile = readKeyFile(keyFileName); // Open keyfile

    if (NULL == keyfile) {
        printf("error allocating memory for keyfile\n");
        return NULL;
    }

    char *secretfile = readFile(secretFileName);
    if (NULL == secretfile) {
        printf("Couldn't open file\n");
        return NULL;
    }


    // Get next char
    c = secretfile[index++];
    do {
        // Holds current string to put in encodedMessage
        // Longest int64 is 19 characters + two brackets + minus sign + escape character = 23
        char currentString[23];
        // If the charater is letter or a space
        if (isLetter(&c) || c == 32) {
            int charIndex = 0;
            // Just add a space if character is space
            if (c == 32) {
                sprintf(currentString, " ");
            }
                // Add a minus sign and search for lowcase of current number
            else if (isHighCase(&c)) {
                charIndex = findNextIndex(c + 32, keyfile, lastIndex, d);
                sprintf(currentString, "[-%d]", charIndex);
            }
                // Print next lowcase of current number
            else {
                charIndex = findNextIndex(c, keyfile, lastIndex, d);
                sprintf(currentString, "[%d]", charIndex);
            }
            lastIndex = charIndex;

            if (currentString != NULL) {
                if (firstSave == 0) {
                    // Cudos til Fredrick
                    // If the string is not yet put into memory, it had no escape character to look for. Therefore,
                    // check for
                    strncpy(encodedMessage, currentString, (strlen(currentString)) + 1);
                    firstSave++;
                } else {
                    // Concatinate the string on the encoded message.
                    char *dest = strncat(encodedMessage, currentString, (strlen(currentString)) + 1);
                    if (dest == NULL) {
                        printf("error writing to encoded file");
                        return NULL;
                    }
                }
            }
        }

        c = secretfile[index++];
    } while(c != '\0'); // While we haven't read the break character

    // free files we don't need anymore
    free(keyfile);
    free(secretfile);

    return encodedMessage;
}

