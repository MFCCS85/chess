
#include <stdio.h>
#include <assert.h>
#include "chess.h"

void test_init_board() {
  init_board();
  assert(board[1][0].type == PAWN);
  assert(board[1][0].color == BLACK);
  assert(board[6][7].type == PAWN);
  assert(board[6][7].color == WHITE);
  assert(board[4][4].type == EMPTY);
  printf("test_init_board passed\n");
}

void test_move_to() {
  Coord from = {0, 1}; // black pawn
  Coord to = {0, 3};
  move_to(from, to);
  assert(board[3][0].type == PAWN);
  assert(board[3][0].color == BLACK);
  assert(board[1][0].type == EMPTY);
  printf("test_move_to passed\n");
}

int main() {
  test_init_board();
  test_move_to();
}
