#include <iostream>
#include <vector>

using namespace std;

template <int x>
class NdimMatrix
{
private:
  vector<NdimMatrix<x-1>>* matrix;
  
public:
  NdimMatrix(): NdimMatrix<x>(0){};
  
  NdimMatrix(int size){
    matrix = new vector<NdimMatrix<x-1>>[size];
    for(int i = 0; i < size; i++){
      matrix->push_back(NdimMatrix<x-1>(size));
    }
  }
  NdimMatrix<x-1>& operator[](int whatever){
    return matrix->at(whatever);
  }

  NdimMatrix<x>& operator=(NdimMatrix& newbie){
    matrix = new vector<NdimMatrix<x-1>>(newbie.matrix->size());
    for(size_t i = 0; i < newbie.matrix->size(); i++){
      matrix->at(i) = newbie.matrix->at(i);
    }
    return *this;
  }
  
};

template<>
class NdimMatrix<1>
{
private:
  vector<int>* matrix;

public:
  NdimMatrix(): NdimMatrix<1>(0){};
  
  NdimMatrix(int size){
    matrix = new vector<int>(size);
    for(int i = 0; i < size; i++){
      matrix->push_back(0);
    }
  }
  int& operator[](int whatever){
    return matrix->at(whatever);
  }

  NdimMatrix<1>& operator=(NdimMatrix& newbie){
    matrix = new vector<int>(newbie.matrix->size());
    for(size_t i = 0; i < newbie.matrix->size(); i++){
      matrix->at(i) = newbie.matrix->at(i);
    }
    return *this;
  }
};

  
  

int main(){
  NdimMatrix<3> n(9); // a cube with 9 * 9 * 9 elements
  NdimMatrix<6> m(5); // a matrix in six dimensions with 5 * 5 * 5 * 5 * 5 * 5 elements
  m[1][3][2][1][4][0] = 7;
  NdimMatrix<3> t(5);
  t = m[1][3][2];      // assign part (slice) of m to t, the dimensions and element size matches
  t[1][4][0] = 2;      // changes t but not m
  std::cout << m[1][3][2][1][4][0] << std::endl; // 7
  std::cout << t[1][4][0] << std::endl;          // 2
  return 0;
}
