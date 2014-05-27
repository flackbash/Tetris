#include <stdio.h>
#include <ncurses.h>

// The position of the character.
int rowIndexNew;
int colIndexNew;
int rowIndexOld = 10;
int colIndexOld = 55;

int left = 50;
int right = 60;
int top = 10;
int bottom = 30;

int count = 0;

// _____________________________________________________________________________
void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
}

// _____________________________________________________________________________
void drawField() {
  // print horizontal border
  for (int x = left + 1; x <= right; x++) {
    printf("\x1b[%d;%dH", bottom, x);
    printf("-");
  }
  // print vertical border
  for (int y = top; y <= bottom; y++) {
    printf("\x1b[%d;%dH", y, left);
    printf("|");
    printf("\x1b[%d;%dH", y, right + 1);
    printf("|");
  }
}

// _____________________________________________________________________________
void moveTetromino(int key) {
  rowIndexOld = rowIndexNew;
  colIndexOld = colIndexNew;
  if (rowIndexNew < bottom - 4) {  // minus 4 because of the length of the Tetr.
    switch (key) {
      case 66:  // Arrow down.
        rowIndexNew++;
        break;
      case 67:  // Arrow right.
        if (colIndexNew < right) {
          colIndexNew++;
        }
        break;
      case 68:  // Arrow left.
        if (colIndexNew > left +1) {
          colIndexNew--;
        }
        break;
    }
  } else {
    rowIndexNew = 10;
    colIndexNew = 55;
    rowIndexOld = rowIndexNew;
    colIndexOld = colIndexNew;
  }
  if (count % 300 == 0) { rowIndexNew++; }
}

// _____________________________________________________________________________
void removeTetromino() {
  // if Tetromino moved down delete only the uppermost part of the old one
  if (rowIndexNew > rowIndexOld) {
    printf("\x1b[%d;%dH", rowIndexOld, colIndexOld);
    printf(" ");
  }
  // if Tetromino moved sidewards delete the whole of the old Tetromino
  if (colIndexNew < colIndexOld || colIndexNew > colIndexOld) {
    for (int i = 0; i < 4; i++) {
      printf("\x1b[%d;%dH", rowIndexOld + i, colIndexOld);
      printf(" ");
    }
  }
}

// _____________________________________________________________________________
void showTetromino() {
  // Todo: find a way to display the Tetromino correctly without using ugly code
  // print red when Tetromino reaches the bottom
  if (rowIndexNew == bottom - 4) {
    printf("\x1b[31m");
  } else { printf("\x1b[0m");}
  printf("\x1b[%d;%dH", rowIndexNew, colIndexNew);
  printf("O");
  printf("\x1b[%d;%dH", rowIndexNew + 1, colIndexNew);
  printf("O");
  printf("\x1b[%d;%dH", rowIndexNew + 2, colIndexNew);
  printf("O");
  printf("\x1b[%d;%dH", rowIndexNew + 3, colIndexNew);
  printf("O");
  // stop printing red
  printf("\x1b[0m");
  fflush(stdout);
  removeTetromino();
}
