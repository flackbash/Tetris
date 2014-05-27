#ifndef TETRIS_TETRIS_H_
#define TETRIS_TETRIS_H_

// Initialize the terminal (no echo, no wait for return, non-blocking read).
void initTerminal();

// Draw boarders to determine the Tetris field.
void drawField();

// Move the character according to the given key.
void moveTetromino(int key);

// Delete the old Tetromino.
void removeTetromino();

// Draw the character.
void showTetromino();

#endif  // TETRIS_TETRIS_H_
