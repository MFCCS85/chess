#include "chess.h"
#include <stdio.h>
#include <string.h>

Piece w_empty = {EMPTY, WHITE};

Piece w_pawn = {PAWN, WHITE};
Piece w_rook = {ROOK, WHITE};
Piece w_knight = {KNIGHT, WHITE};
Piece w_bishop = {BISHOP, WHITE};
Piece w_queen = {QUEEN, WHITE};
Piece w_king = {KING, WHITE};

Piece b_pawn = {PAWN, BLACK};
Piece b_rook = {ROOK, BLACK};
Piece b_knight = {KNIGHT, BLACK};
Piece b_bishop = {BISHOP, BLACK};
Piece b_queen = {QUEEN, BLACK};
Piece b_king = {KING, BLACK};

Piece board[8][8];

const char piece_symbols[2][6] = {
    {'p', 'r', 'n', 'b', 'q', 'k'}, // BLACK
    {'P', 'R', 'N', 'B', 'Q', 'K'}  // WHITE
};

// Board Stuff
void init_board() {
  Piece first_row[8] = {b_rook, b_knight, b_bishop, b_queen,
                        b_king, b_bishop, b_knight, b_rook};
  memcpy(board[0], first_row, sizeof(first_row));
  for (int col = 0; col < 8; col++) {
    board[1][col] = b_pawn;
  }

  for (int row = 2; row < 6; row++) {
    for (int col = 0; col < 8; col++) {
      board[row][col] = w_empty;
    }
  }

  for (int col = 0; col < 8; col++) {
    board[6][col] = w_pawn;
  }
  Piece last_row[8] = {w_rook, w_knight, w_bishop, w_queen,
                       w_king, w_bishop, w_knight, w_rook};
  memcpy(board[7], last_row, sizeof(last_row));
}

void print_board(enum COLOR color) {
  if (color == BLACK) {
    for (int row = 7; row >= 0; row--) {
      for (int col = 7; col >= 0; col--) {
        print_piece(board[row][col]);
      }
      printf("\n");
    }
  } else {
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        print_piece(board[row][col]);
      }
      printf("\n");
    }
  }
}

// Piece Stuff
void add_piece(Piece piece, Coord coord) {
  board[coord.row][coord.col] = piece;
}
void remove_piece(Coord coord) { board[coord.row][coord.col].type = EMPTY; }
void print_piece(Piece piece) {
  if (piece.type == EMPTY) {
    printf(" ");
    return;
  }
  printf("%c", piece_symbols[piece.color][piece.type]);
}

// Game Stuff
int is_valid_move(Piece piece, Coord coord) { return 1; }

void move_to(Coord from, Coord to) {
  Piece piece = board[from.row][from.col];
  if (is_valid_move(piece, to)) {
    add_piece(piece, to);
    remove_piece(from);
  }
}

// Coord *notation_to_coords(char *notation) {}
