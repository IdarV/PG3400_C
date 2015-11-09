#include <stdio.h>
#include "fileReader.c"
#include "fileEncoder.c"
#include "fileDecoder.c"

int main(int argc, char *argv[]) {
    char *filename = "hey.txt";
    char *secretFile = "secretMessage.txt";
    char *filetext = encode(filename, secretFile);

    if (filetext == NULL) {
        return -1;
    }
    char *supersecret = decode(filename, filetext);

    if (supersecret == NULL) {
        return -1;
    }

    printf("%s\n", filetext);
    printf("%s\n", supersecret);

    free(filetext);
    free(supersecret);

    return 0;
}