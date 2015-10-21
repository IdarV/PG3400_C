#include <stdio.h>

void increase_std(){
    static int svalue = 1;
    printf("svalue: %d\n", svalue++);
    printf("HE");
}

int main(int argc, char *argv[]){

    for(int i = 0; i < 5; i++){
        increase_std();
    }

    return 0;
}

