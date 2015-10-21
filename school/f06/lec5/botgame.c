//Let us get you to use a library now. It is ncurses - 
// To install it you can type sudo apt-get install libncurses5-dev 
// The version might vary - but it is a classical library. 
// When you compile - you need to link it against the library.
// gcc -std=c11 main.c -lncurses -o botgame 
// The above command will help you with the compilation. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>

typedef struct bot{
  short ar[3][3];
}bot;

typedef struct botList{
  struct botList *next;
  bot current;
}botList;

int addBot();



int main(int argc, char *argv[]){

  
  srand (time(NULL));
  //A simple seed to random numbers
  initscr();
  printw("Welcome to the crappy bot game. You life is 100\n");//
  int numBots;
  printw("100\n111\n101");//Example bot - this is not how you should be printing
                          // though
  timeout(2000);//This is how you do a timed-input. in milliseconds
  int c = getch(); // And just normal input - it gives -1 if the input is
                   //  timedout
  
  
  
  
  printf("Game Summary  and timeout character is %d\n",c);



  endwin();
  return 0;
}
