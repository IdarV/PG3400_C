#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
 * Kills the program with error message.
 * source: http://c.learncodethehardway.org/book/ex18.html
 */
void die(const char *message) {
    if (errno) {
        // If errno is set, print the error
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

int main(int argc, char *argv[]){
    if(argc < 2) die("Didn't find any file argument");
    char *filename = argv[1];


}