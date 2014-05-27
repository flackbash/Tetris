#include <gtest/gtest.h>
#include "./Tetris.h"

extern int rowIndexOld;
extern int colIndexOld;
extern int rowIndexNew;
extern int colIndexNew;

// _____________________________________________________________________________
TEST(TetrisTest, moveTetromino) {
  rowIndexNew = 22;
  colIndexNew = 51;
  moveTetromino(66);  // Arrow down.
  ASSERT_EQ(24, rowIndexNew);
  ASSERT_EQ(51, colIndexNew);
  moveTetromino(67);  // Arrow right.
  ASSERT_EQ(25, rowIndexNew);
  ASSERT_EQ(52, colIndexNew);
  moveTetromino(68);  // Arrow left.
  ASSERT_EQ(26, rowIndexNew);
  ASSERT_EQ(51, colIndexNew);
  moveTetromino(68);  // Arrow left.
  ASSERT_EQ(11, rowIndexNew);
  ASSERT_EQ(55, colIndexNew);
  rowIndexNew = 24;
  colIndexNew = 60;
  moveTetromino(67);  // Arrow right.
  ASSERT_EQ(25, rowIndexNew);
  ASSERT_EQ(60, colIndexNew);
  moveTetromino(66);  // Arrow down.
  ASSERT_EQ(27, rowIndexNew);
  ASSERT_EQ(60, colIndexNew);
}
