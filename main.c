#include "chess.h"

int main() {
  init_board();
  print_board(BLACK);
  Coord from = {0, 0};
  Coord to = {0, 2};
  move_to(from, to);
  print_board(BLACK);
}
