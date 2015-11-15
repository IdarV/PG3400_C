#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringHelpers.h"
#include "secretCoder.h"
#include "secretDecoder.h"
#include "secretCoderCracker.h"
#include "arrayList.h"
#include "fileReader.h"

int main(int argc, char *argv[]) {
    if (argc > 3) {
        char *arg = argv[1];
        if (strcmp(arg, "encode") == 0) {
            //./program encode ../secretMessage.txt ../HE2/songLibrary/wakaWaka.txt
            char *secretMessageFile = argv[2];
            char *keyfile = argv[3];
            int *status = malloc(sizeof(int));
            *status = 0;

            char *encodedMessage = encode(keyfile, secretMessageFile, status);
            printf("Encoded message:\n%s\n", encodedMessage);
            if(*status != 0){
                printf("--Warning: not all character were encoded\n");
            }
            free(status);
            free(encodedMessage);
        }
        else if (strcmp(arg, "decode") == 0) {
            // ./program decode ../encodedMessage.txt ../HE2/songLibrary/wakaWaka.txt
            char *secretMessageFile = argv[2];
            char *secretMessage = readFile(secretMessageFile);
            char *keyfile = readKeyFile(argv[3]);
            int *status = malloc(sizeof(int));
            *status = 0;

            char *decodedMessage = decode(keyfile, secretMessage, status);

            printf("Decoded message:\n%s", decodedMessage);
            if(*status != 0){
                printf("--Warning: not all character were encoded\n");
            }

            free(status);
            free(keyfile);
            free(decodedMessage);
            free(secretMessage);
        }
        else if (strcmp(arg, "crack") == 0) {
            //./program crack ../encodedMessage.txt ../HE2/songLibrary
            char *encodedMessageFile = argv[2];
            char *encodedMessage = readFile(encodedMessageFile);
            char *keyFilesFolder = argv[3];
            char *wordsListFile = "/usr/share/dict/words";

            char *result = crack(encodedMessage, keyFilesFolder, wordsListFile);
            printf("Most likely key-file is %s\n", result);
            free(encodedMessage);
            free(result);
        }
    }
}
