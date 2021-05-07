#ifndef AI1_H
#define AI1_H

#include "ChessBoard.cpp"

class AI1{
  
 public:
  ChessBoard* board = new ChessBoard(board_size);
  bool isWhite = true;
  int pieces_left = 16;

  void make_move();
  int get_pieces_left();
  ChessBoard *& get_board();
  bool get_isWhite();
};

#endif
