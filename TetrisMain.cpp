#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "./Tetris.h"

extern int rowIndexOld;
extern int colIndexOld;
extern int rowIndexNew;
extern int colIndexNew;
extern int count;

// Main function.
int main(int argc, char** argv) {
  rowIndexNew = 10;
  colIndexNew = 55;
  initTerminal();
  while (true) {
    drawField();
    int key = getch();
    moveTetromino(key);
    showTetromino();
    usleep(1000);
    count++;
    // Arrow up will exit the program
    if (key == 65) {break;}
  }
  endwin();
}
