#ifndef BISHOP_CPP
#define BISHOP_CPP
#include "Bishop.h"
#include "ChessBoard.cpp"


int Bishop::validMove(int to_x, int to_y){
  if(to_x >= 1 && to_x <= 8 && to_y >= 1 && to_y <= 8){
    if(this->board->get_state_idx(to_x,to_y) == 0){
      return 1;
    }
    else if(this->isWhite != this->board->get_state_idx(to_x,to_y)->isWhite){
      return 2;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
}
char32_t Bishop::utfRepresentation(){
  if(this->isWhite == true){
    return L'♗';
  }
  else{
    return L'♝';
  }
}
char Bishop::latin1Representation(){
  if(this->isWhite == true){
    return 'B';
  }
  else{
    return 'b';
  }
}

bool Bishop::capturingMove(int to_x, int to_y){
  if(validMove(to_x,to_y) == 2){
    return true;
  }
  else{
    return false;
  }
}

bool Bishop::nonCapturingMove(int to_x, int to_y){
  if(validMove(to_x,to_y) == 1){
    return true;
  }
  else{
    return false;
  }
}
vector<ChessMove> Bishop::capturingMoves(){
  vector<ChessMove> list;
  int i = 1;
  bool next5 = false;
  bool next6 = false;
  bool next7 = false;
  bool next8 = false;

  while(i < 8){
   

    if(capturingMove(this->x + i,this->y + i) == true && next5 == false){
      struct ChessMove M = {this->x, this->y, this->x + i, this->y + i, this};
      list.push_back(M);
      next5 = true;
    }
    else if(nonCapturingMove(this->x + i, this->y + i) == false && next5 == false){
      next5 = true;
    }

    if(capturingMove(this->x + i,this->y - i) == true && next6 == false){
      struct ChessMove M = {this->x, this->y, this->x + i, this->y - i, this};
      list.push_back(M);
      next6 = true;
    }
    else if(nonCapturingMove(this->x + i, this->y - i) == false && next6 == false){
      next6 = true;
    }

    if(capturingMove(this->x - i,this->y - i) == true && next7 == false){
      struct ChessMove M = {this->x, this->y, this->x - i, this->y - i, this};
      list.push_back(M);
      next7 = true;
    }
    else if(nonCapturingMove(this->x - i, this->y - i) == false && next7 == false){
      next7 = true;
    }

    if(capturingMove(this->x - i,this->y + i) == true && next8 == false){
      struct ChessMove M = {this->x, this->y, this->x - i, this->y + i, this};
      list.push_back(M);
      next8 = true;
    }
    else if(nonCapturingMove(this->x - i, this->y + i) == false && next8 == false){
      next8 = true;
    }
    
    i++;
  }
  
  return list;
}
vector<ChessMove> Bishop::nonCapturingMoves(){
  vector<ChessMove> list;
  int i = 1;
  bool next5 = false;
  bool next6 = false;
  bool next7 = false;
  bool next8 = false;

  while(i < 8){
    
    if(nonCapturingMove(this->x + i,this->y + i) == true && next5 == false){
      struct ChessMove M = {this->x, this->y, this->x + i, this->y + i, this};
      list.push_back(M);
    }
    else{
      next5 = true;
    }
    
    if(nonCapturingMove(this->x + i,this->y - i) == true && next6 == false){
      struct ChessMove M = {this->x, this->y, this->x + i, this->y - i, this};
      list.push_back(M);
    }
    else{
      next6 = true;
    }
    
    if(nonCapturingMove(this->x - i,this->y - i) == true && next7 == false){
      struct ChessMove M = {this->x, this->y, this->x - i, this->y - i, this};
      list.push_back(M);
    }
    else{
      next7 = true;
    }
    
    if(nonCapturingMove(this->x - i,this->y + i) == true && next8 == false){
      struct ChessMove M = {this->x, this->y, this->x - i, this->y + i, this};
      list.push_back(M);
    }
    else{
      next8 = true;
    }
    
    i++;
  }
   
  return list;
}

#endif
