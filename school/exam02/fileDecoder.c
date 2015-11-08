#include "fileDecoder.h"
#include "fileReader.h"
#include <string.h>

int getNumber(char *secretMessage, int *index){
    bool end = false;
    int this_index = 0;
    char number_arry[100] = {};
    while(!end){
        char c = secretMessage[*index + this_index + 1];
        if(c == ']'){
            end = true;
        } else{
        number_arry[this_index] = c;
            this_index++;

        }
    }

//    for(int i = 0; i < this_index; i++){
//        printf("%c", number_arry[i]);
//    }
//    printf("\n");
    *index = *index + this_index;
    int number_represented;
    sscanf(number_arry, "%d", &number_represented);
    return number_represented;
}

char *decode(char *keyFileName, char *secretMessage) {
    char *keyFile = readKeyFile(keyFileName);

    int secretMessageSize = strlen(secretMessage);
    printf("secretMessageSize: %d\n", secretMessageSize);

    bool insideSquareBracket = false;
    for (int i = 0; i < secretMessageSize; i++) {
        char currentChar = secretMessage[i];

        if (currentChar == '[') {
            int number = getNumber(secretMessage, &i);
//            printf("number: %d\n", number);
            printf("%c", keyFile[number]);
        }

        else {
            //printf("%c ", currentChar);
        }

    }

    return keyFile;
}