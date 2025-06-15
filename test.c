
#include "chess.h"
#include <assert.h>
#include <stdio.h>

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

void test_algebraic_to_coord() {
  Coord t1 = algebraic_to_coord("a1");
  Coord t2 = algebraic_to_coord("a2");
  Coord t3 = algebraic_to_coord("a3");
  Coord t4 = algebraic_to_coord("a4");

  assert(t1.row == 0);
  assert(t2.row == 1);
  assert(t3.row == 2);
  assert(t4.row == 3);
}

int main() {
  test_init_board();
  test_move_to();
  test_algebraic_to_coord();
}
