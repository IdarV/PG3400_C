#include "stringHelpers.h"
#include "secretDecoder.h"
#include "fileReader.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Get the number in between two brackets in an encoded message
int getNumber(char *secretMessage, int *index) {
    bool end = false;
    int this_index = 1;
    char number_arry[100] = {};

    while (!end) {
        char c = secretMessage[*index + this_index];

        if (c == ']') {
            // If char is end-square bracket, we are finished getting number
            end = true;
        } else {
            // Add current char to array
            number_arry[this_index - 1] = c;
            this_index++;
        }
    }

    // Increase original index, so its outside of the brackets
    *index += this_index;

    // Parse number to int, and return it
    int number_represented = -1;
    sscanf(number_arry, "%d", &number_represented);
    return number_represented;
}

// Decode secretMessage with Keyfile
char *decode(char *keyFile, char *secretMessage, int *status) {
    // Allocate some space for cracked message
    char *crackedMessage = malloc(strlen(secretMessage) / 3 * sizeof(char));
    int crackedMessageIndex = 0;

    // Get size of keyfile
    int keyFileSize = strlen(keyFile);

    // Get size of secret message
    int secretMessageSize = strlen(secretMessage);

    // Loop through secret message
    for (int i = 0; i < secretMessageSize - 1; i++) {
        char currentCrackedChar = secretMessage[i];

        // If we meet square brackets, get the number inside it and decode with
        if (currentCrackedChar == '[') {
            int number = getNumber(secretMessage, &i);
            if (number > keyFileSize) {
                *status = 1;
            } else {


                if (number >= 0) {
                    crackedMessage[crackedMessageIndex++] = keyFile[number];
                }
                else {
                    // If number is negative, it's an indication that it's ment to be high-case. Make number positive
                    number *= -1;
                    // add number as highcase (Unicode conv low->high = +32)
                    crackedMessage[crackedMessageIndex++] = keyFile[number] - 32;
                }
            }
        }
            // If not a square bracket, its not encoded. Just add it
        else {
            crackedMessage[crackedMessageIndex++] = currentCrackedChar;
        }
    }

    // Add breack character at end
    crackedMessage[crackedMessageIndex] = '\0';
    printf("%s\n%s\n", crackedMessage, secretMessage);
    return crackedMessage;
}
