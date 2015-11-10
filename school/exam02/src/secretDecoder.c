#include "stringHelpers.h"
#include "secretDecoder.h"
#include "fileReader.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Get the number in between two brackets
int getNumber(char *secretMessage, int *index) {
    bool end = false;
//    bool highCase = false;
    int this_index = 1;
    char number_arry[100] = {};
    while (!end) {
        char c = secretMessage[*index + this_index];
        // End is we get to the end of this number
        if (c == ']') {
            end = true;
        } else {
            number_arry[this_index - 1] = c;
            this_index++;
        }
    }

    // Increase original index, so we'll get out of the brackets
    *index = *index + this_index;

    // Parse number to int
    int number_represented = -1;
    sscanf(number_arry, "%d", &number_represented);

    // Return number
    return number_represented;
}

// Decode secretMessage with Keyfile
char *decode(char *keyFileName, char *secretMessage) {
    // Read the keyFile
    char *keyFile = readKeyFile(keyFileName);
    char *crackedMessage = malloc(strlen(secretMessage) / 3);
    int crackedMessageIndex = 0;

    // Get size of secret message
    int secretMessageSize = strlen(secretMessage);
    for (int i = 0; i < secretMessageSize - 1; i++) {
        char currentCrackedChar = secretMessage[i];
        // TODO: RETURN NULL IF NOT FOUND OR SOMETHING

        if (currentCrackedChar == '[') {
            int number = getNumber(secretMessage, &i);
            if (number >= 0) {
                crackedMessage[crackedMessageIndex++] = keyFile[number];
            } else {
                // Make number positive
                number *= -1;
                // Print highcase(Unicode conv low->high = +32)
                crackedMessage[crackedMessageIndex++] = keyFile[number] - 32;
            }
        }

        else {
            crackedMessage[crackedMessageIndex++] = currentCrackedChar;
        }
    }

    crackedMessage[crackedMessageIndex] = '\0';

    free(keyFile);
    return crackedMessage;
}