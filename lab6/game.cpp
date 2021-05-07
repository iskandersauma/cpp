#include <iostream>

#include "AI1.cpp"
#include "AI2.cpp"

using std::vector; using std::stringstream; using std::cout; using std::endl;
using namespace std;

int main(){
  stringstream s;
  ChessBoard chess = ChessBoard(board_size);
  
  s << "rnbqkbnr" << endl;
  s << "pppppppp" << endl;
  s << "........" << endl;
  s << "........" << endl;
  s << "........" << endl;
  s << "........" << endl;
  s << "PPPPPPPP" << endl;
  s << "RNBQKBNR" << endl;
  s >> chess;
  cout<<chess;

  AI1* data1 = new AI1();
  AI2* data2 = new AI2();
  data1->board = (&chess);

  bool winner = false;
  string turn = "data1";

  while(winner == false){
    if(turn == "data1"){
      data1->make_move();
      
      turn = "data2";

      data2->board = data1->board;
      if(data2->get_board()->check_pieces(data2->get_isWhite()) == 0){
	winner = true;
	turn = "AI2";
      }
    }
    else{
      data2->make_move();
      turn = "data1";
      data1->get_board()->reset(*(data2->get_board()));
      
      if(data1->get_board()->check_pieces(data1->get_isWhite()) == 0){
	winner = true;
	turn = "AI1";
      }
    }
    cout<<*(data1->get_board());
    
  }
  
  cout<<"The winner is: "<<turn << endl;

  



  /*
  cout<<*(data1->get_board());
  
  vector<ChessMove> v14 = (*(data1->get_board())).capturingMoves(data1->get_isWhite());
  vector<ChessMove> v15 = (*(data1->get_board())).nonCapturingMoves(data1->get_isWhite());
  cout<<"still no problems"<<endl;
  
  cout<<v14.size()<<endl;
  cout<<v15.size()<<endl;
  data1->get_board()->move_piece(v15.front());
  cout<<*(data1->get_board());

  cout<<data1->get_board()->check_pieces(data1->get_isWhite())<<endl;
  */
}
