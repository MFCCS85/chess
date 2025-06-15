enum PTYPE { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, EMPTY };

enum COLOR { BLACK, WHITE };

typedef struct {
  enum PTYPE type;
  enum COLOR color;
} Piece;

typedef struct {
  int col;
  int row;
} Coord;

extern Piece board[8][8];

void add_piece(Piece piece, Coord coord);
void remove_piece(Coord coord);
void print_piece(Piece piece);

int is_valid_move(Piece piece, Coord coord);
void move_to(Coord from, Coord to);

void init_board();
void print_board(enum COLOR color);
