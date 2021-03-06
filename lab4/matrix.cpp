#include <iostream>
#include <algorithm>
#include <regex>
#include <string>
#include "matrix.h"
using namespace std;

//contrstructors
template <class T>
Matrix<T>::Matrix(){
  this->m_rows = 1;
  this->m_cols = 1;
  this->m_capacity =1;
  this->m_vec = new T[1];
}

template <class T>
Matrix<T>::Matrix(unsigned int row){
  set_rows(row);
  set_cols(row);
  set_capacity(row);
  this->m_vec = new T[row*row];
  for(int i = 0; i < row; i++){
    for(int j = 0; j < row; j++){
      this->m_vec[j+i*row] = 0;
    }
  }
}

template <class T>
Matrix<T>::Matrix(unsigned int row, unsigned int col){
  set_rows(row);
  set_cols(col);
  set_capacity(row,col);
  this->m_vec = new T[row*col];
  for(unsigned int i = 0; i < row; i++){
    for(unsigned int j = 0; j < col; j++){
      this->m_vec[j+i*col] = 0;
    }
  }
}

template <class T>
Matrix<T>::Matrix(const T size){
  this->m_rows = size;
  this->m_cols = size;
  this->m_capacity = size*size;
  this->m_vec = new T[size*size];
  for(unsigned int i = 0; i < size*size; i++){
    this->m_vec[i] = 0;
  }
}

template <class T>
Matrix<T>::Matrix(Matrix &obj){
  size_t rows = obj.get_rows();
  size_t cols = obj.get_cols();
  this->m_rows = rows;
  this->m_cols = cols;
  this->m_capacity = rows*cols;
  this->m_vec = new T[rows*cols];
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      this->m_vec[j+i*cols] = obj(i,j);
    }
  }
}

template <class T>
Matrix<T>::Matrix(Matrix &&obj){
  size_t rows = obj.get_rows();
  size_t cols = obj.get_cols();
  this->m_rows = rows;
  this->m_cols = cols;
  this->m_capacity = rows*cols;
  this->m_vec = new T[rows*cols];
   for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      this->m_vec[j+i*cols] = obj(i+1,j+1);
    }
  }
  //m_vec = nullptr;   /* why is this one needed*/
}

template <class T> 
Matrix<T>::Matrix(initializer_list<T> l){
  if (fmod(sqrt(l.size()),1) == 0 ){
    this->m_rows = sqrt(l.size());
    this->m_cols = sqrt(l.size());
    this->m_capacity = l.size();
    this->m_vec = new T [l.size()];
    for(int i = 0; i < l.size(); i++){
      this->m_vec[i] = l.begin()[i];
    }
  }
  else{
    cerr<<"invalid input";
  }
}

template <class T>
Matrix<T>::~Matrix(){
  delete [] m_vec;
}

//operators
template <class T>
void Matrix<T>::operator=(Matrix &obj){
  delete [] this->m_vec;
  this->m_rows = obj.get_rows();
  this->m_cols = obj.get_cols();
  this->m_capacity = obj.get_capacity();
  this->m_vec = new T[obj.get_capacity()];
  for(unsigned int i = 0; i < obj.get_rows(); i++){
    for(unsigned int j = 0; j < obj.get_cols();j++){
      this->m_vec[i*obj.get_cols()+j] = obj(i+1,j+1);
    }
  }
}

template <class T>
Matrix<T>& Matrix<T>::operator=(Matrix &&obj){
  if(this!=&obj){
    delete [] this->m_vec;
    this->m_rows = obj.get_rows();
    this->m_cols = obj.get_cols();
    this->m_capacity = obj.get_capacity();
    this->m_vec = new T[obj.get_capacity()];
    for(unsigned int i = 0; i < obj.get_rows(); i++){
      for(unsigned int j = 0; j < obj.get_cols();j++){
	this->m_vec[i*obj.get_cols()+j] = obj(i+1,j+1);
      }
    }
  }
  return *this;
}

template <class T>
T& Matrix<T>::operator()(unsigned int row, unsigned int col){
  if(row > this->m_rows || col > this->m_cols){
    cerr<<"out of range";
  }
  return this->m_vec[(row-1)*m_cols+col-1];
}

template <class T>
void Matrix<T>::operator+=(Matrix &mat){
  if(this->m_rows != mat.m_rows || this->m_cols != mat.m_cols){
    cerr<<"dimension error"<<endl;
  }
  else{
    for(unsigned int i = 0; i < this->m_rows; i++){
      for(unsigned int j = 0; j < this->m_cols; j++){
	this->m_vec[i*this->m_cols+j] += mat.m_vec[i*this->m_cols+j];
      }
    }
  }
}

template <class T>
void Matrix<T>::operator+=(const T number){
  for(unsigned int i = 0; i < this->m_rows; i++){
    for(unsigned int j = 0; j < this->m_cols; j++){
      this->m_vec[i*this->m_cols+j] += number;;
    }
  }
}

template <class T>
void Matrix<T>::operator-=(Matrix &mat){
  if(this->m_rows != mat.m_rows || this->m_cols != mat.m_cols){
    cerr<<"dimension error"<<endl;
  }
  else{
    for(unsigned int i = 0; i < this->m_rows; i++){
      for(unsigned int j = 0; j < this->m_cols; j++){
	this->m_vec[i*this->m_cols+j] -= mat.m_vec[i*this->m_cols+j];
      }
    }
  }
}

template <class T>
void Matrix<T>::operator-=(const T number){
  for(unsigned int i = 0; i < this->m_rows; i++){
    for(unsigned int j = 0; j < this->m_cols; j++){
      this->m_vec[i*this->m_cols+j] -= number;;
    }
  }
}

template <class T>
void Matrix<T>::operator*=(Matrix &mat){
  if(this->m_rows != mat.m_rows || this->m_cols != mat.m_cols){
    cerr<<"dimension error"<<endl;
  }
  else{
    for(unsigned int i = 0; i < this->m_rows; i++){
      for(unsigned int j = 0; j < this->m_cols; j++){
	this->m_vec[i*this->m_cols+j] *= mat.m_vec[i*this->m_cols+j];
      }
    }
  }
}

template <class T>
void Matrix<T>::operator*=(const T number){
  for(unsigned int i = 0; i < this->m_rows; i++){
    for(unsigned int j = 0; j < this->m_cols; j++){
      this->m_vec[i*this->m_cols+j] *= number;;
    }
  }
}

template <class T>
bool Matrix<T>::operator==(Matrix<T> &mat){
  if(m_rows != mat.m_rows || m_cols != mat.m_cols){
    return false;
  }
  else{
    for(unsigned int i = 0; i < m_capacity; i++){
      if(m_vec[i] != mat.m_vec[i]){
	return false;
      }
    }
    return true;
  }
}

template <class T>
Matrix<T> operator+(Matrix<T> &mat1, Matrix<T> &mat2){
  if(mat1.get_rows() != mat2.get_rows() || mat1.get_cols() != mat2.get_cols()){
    cerr<<"dimension error"<<endl;
  }
  else{
    Matrix<T> newmatrix(mat1.get_rows(),mat1.get_cols());
    for(unsigned int i = 1; i < mat1.get_rows()+1; i++){
      for(unsigned int j = 1; j < mat1.get_cols()+1; j++){
	newmatrix(i,j) = mat1(i,j) + mat2(i,j);
      }
    }
    return newmatrix;
  }
}

template <class T>
Matrix<T> operator+(Matrix<T> &mat1, T number){
  Matrix<T> newmatrix(mat1.get_rows(),mat1.get_cols());
  for(unsigned int i = 1; i < mat1.get_rows()+1; i++){
    for(unsigned int j = 1; j < mat1.get_cols()+1; j++){
      newmatrix(i,j) = mat1(i,j) + number;
    }
  }
  return newmatrix;
}

template <class T>
Matrix<T> operator-(Matrix<T> &mat1, Matrix<T> &mat2){
  if(mat1.get_rows() != mat2.get_rows() || mat1.get_cols() != mat2.get_cols()){
    cerr<<"dimension error"<<endl;
  }
  else{
    Matrix<T> newmatrix(mat1.get_rows(),mat1.get_cols());
    for(unsigned int i = 1; i < mat1.get_rows()+1; i++){
      for(unsigned int j = 1; j < mat1.get_cols()+1; j++){
	newmatrix(i,j) = mat1(i,j) - mat2(i,j);
      }
    }
    return newmatrix;
  }
}

template <class T>
Matrix<T> operator-(Matrix<T> &mat1, T number){
  Matrix<T> newmatrix(mat1.get_rows(),mat1.get_cols());
  for(unsigned int i = 1; i < mat1.get_rows()+1; i++){
    for(unsigned int j = 1; j < mat1.get_cols()+1; j++){
      newmatrix(i,j) = mat1(i,j) - number;
    }
  }
  return newmatrix;
}

template <class T>
Matrix<T> operator*(Matrix<T> &mat1, Matrix<T> &mat2){
  if(mat1.get_rows() != mat2.get_rows() || mat1.get_cols() != mat2.get_cols()){
    cerr<<"dimension error"<<endl;
  }
  else{
    Matrix<T> newmatrix(mat1.get_rows(),mat1.get_cols());
    for(unsigned int i = 1; i < mat1.get_rows()+1; i++){
      for(unsigned int j = 1; j < mat1.get_cols()+1; j++){
	newmatrix(i,j) = mat1(i,j) * mat2(i,j);
      }
    }
    return newmatrix;
  }
}

template <class T>
Matrix<T> operator*(Matrix<T> &mat1, T number){
  Matrix<T> newmatrix(mat1.get_rows(),mat1.get_cols());
  for(unsigned int i = 1; i < mat1.get_rows()+1; i++){
    for(unsigned int j = 1; j < mat1.get_cols()+1; j++){
      newmatrix(i,j) = mat1(i,j) * number;
    }
  }
  return newmatrix;
}

//methods
template <class T>
void Matrix<T>::reset(){
  for(int i = 0; i< m_capacity; i++){
    m_vec[i] = T();
  }
}

template <class T>
void Matrix<T>::set_rows(T rows){
  this->m_rows = rows;
}

template <class T>
void Matrix<T>::set_cols(T cols){
  this->m_cols = cols;
}

template <class T>
void Matrix<T>::set_capacity(T rows, T cols){
  this->m_capacity = rows*cols;
}

template <class T>
void Matrix<T>::set_capacity(T rows){
  this->m_capacity = rows*rows;
}

template <class T>
size_t Matrix<T>::get_rows(){
  return this->m_rows;
}

template <class T>
size_t Matrix<T>::get_cols(){
  return this->m_cols;
}

template <class T>
size_t Matrix<T>::get_capacity(){
  return this->m_capacity;
}

template <class T>
void Matrix<T>::insert_row(unsigned int row){
  if(row >= get_rows()){
    cerr<<"too high";
  }
  else{
    T* temp = new T[m_capacity];
    for(unsigned int i = 0; i < m_capacity; i++){
      temp[i] = m_vec[i];
    }
    delete [] m_vec;
    m_vec = new T[(m_rows+1)*m_cols];

    for(unsigned int i = 0; i < row-1;i++){
      for(unsigned int j = 0; j < m_cols; j++){
	m_vec[i*m_cols+j] = temp[i*m_cols+j];
      }
    }

    for(unsigned int i = 0; i < m_cols; i++){
      m_vec[(row-1)*m_cols+i] = 0;
    }

    for(unsigned int i = row; i < m_rows+1; i++){
      for(unsigned int j = 0; j < m_cols; j++){
	m_vec[i*m_cols+j] = temp[(i-1)*m_cols+j];
      }
    }
    m_rows++;
    m_capacity = m_cols*m_rows;
    delete [] temp;
  }
}

template <class T>
void Matrix<T>::append_row(unsigned int row){
  if(row > get_rows()){
    cerr<<"too high";
  }
  else{
    T* temp = new T[m_capacity];
    for(unsigned int i = 0; i < m_capacity; i++){
      temp[i] = m_vec[i];
    }
    
    delete [] m_vec;
    m_vec = new T[(m_rows+1)*m_cols];
    for(unsigned int i = 0; i < row;i++){
      for(unsigned int j = 0; j < m_cols; j++){
	m_vec[i*m_cols+j] = temp[i*m_cols+j];
      }
    }

    for(unsigned int i = 0; i < m_cols; i++){
      m_vec[row*m_cols+i] = 0;
    }

    for(unsigned int i = row+1; i < m_rows+1;i++){
      for(unsigned int j = 0; j < m_cols;j++){
	m_vec[i*m_cols+j] = temp[(i-1)*m_cols+j];
      }
    }
    m_rows++;
    m_capacity = m_cols*m_rows;
    delete [] temp;
  }
}

template <class T>
void Matrix<T>::insert_cols(unsigned int col){
  if(col >= m_cols){
    cerr<<"too high";
  }
  else{
    T* temp = new T[m_capacity];
    for(unsigned int i = 0; i < m_capacity; i++){
      temp[i] = m_vec[i];
    }

    delete [] m_vec;
    m_vec = new T[m_rows*(m_cols+1)];
    
    for(unsigned int i = 0; i < col-1; i++){
      for(unsigned int j = 0; j < m_rows; j++){
	m_vec[j*(m_cols+1)+i] = temp[j*m_cols+i];
      }
    }

    for(unsigned int i = 0; i < m_rows; i++){
      m_vec[i*(m_cols+1)+col-1] = 0;
    }

    for(unsigned int i = col; i < m_cols+1;i++){
      for(unsigned int j = 0; j < m_rows; j++){
	m_vec[j*(m_cols+1)+i] = temp[j*m_cols+(i-1)];
      }
    }
    m_cols++;
    m_capacity = m_rows*m_cols;
    delete [] temp;
  }
}

template <class T>
void Matrix<T>::append_cols(unsigned int col){
  if(col > m_cols){
    cerr<<"too high";
  }
  else{
    T* temp = new T[m_capacity];
    for(unsigned int i = 0; i < m_capacity; i++){
      temp[i] = m_vec[i];
    }

    delete [] m_vec;
    m_vec = new T[m_rows*(m_cols+1)];

    for(unsigned int i = 0; i < col; i++){
      for(unsigned int j = 0; j < m_rows; j++){
	m_vec[j*(m_cols+1) + i] = temp[j*m_cols+i];
      }
    }

    for(unsigned int i = 0; i < m_rows; i++){
      m_vec[i*(m_cols+1)+col] = 0;
    }

    for(unsigned int i = col+1; i < m_cols+1; i++){
      for(unsigned int j = 0; j < m_rows; j++){
	m_vec[j*(m_cols+1)+i] = temp[j*m_cols+i-1];
      }
    }
    m_cols++;
    m_capacity = m_rows*m_cols;
    delete [] temp;
  }
}

template <class T>
void Matrix<T>::remove_row(unsigned int row){
  if(row > m_rows){
    cerr<<"out or range"<<endl;
  }
  else{
    T* temp = new T[m_capacity];
    for(unsigned int i = 0; i < m_capacity; i++){
      temp[i] = m_vec[i];
    }

    delete [] m_vec;
    m_vec = new T[(m_rows-1)*m_cols];

    for(unsigned int i = 0; i < row-1;i++){
      for(unsigned int j = 0; j < m_cols; j++){
	m_vec[i*m_cols+j] = temp[i*m_cols+j];
      }
    }

    for(unsigned int i = row; i < m_rows; i++){
      for(unsigned int j = 0; j < m_cols; j++){
	m_vec[(i-1)*m_cols+j] = temp[i*m_cols+j];
      }
    }
    m_rows--;
    m_capacity = m_cols*m_rows;
    delete [] temp;    
  }
}

template <class T>
void Matrix<T>::remove_cols(unsigned int col){
  if(col > m_cols){
    cerr<<"out or range"<<endl;
  }
  else{
    T* temp = new T[m_capacity];
    for(unsigned int i = 0; i < m_capacity; i++){
      temp[i] = m_vec[i];
    }

    delete [] m_vec;
    m_vec = new T[m_rows*(m_cols-1)];

    for(unsigned int i = 0; i < col-1;i++){
      for(unsigned int j = 0; j < m_rows; j++){
	m_vec[j*(m_cols-1)+i] = temp[j*m_cols+i];
      }
    }
    
    for(unsigned int i = col; i < m_cols; i++){
      for(unsigned int j = 0; j < m_rows; j++){
	m_vec[j*(m_cols-1)+i-1] = temp[j*m_cols+i];
      }
    }
    m_cols--;
    m_capacity = m_cols*m_rows;
    delete [] temp;    
  }
}

template <class T>
T* Matrix<T>::begin(){
  T* begin = &m_vec[0];
  return begin;
}

template <class T>
T* Matrix<T>::end(){
  T* end = &m_vec[m_capacity-1];
  return end;
}

template <class T>
ostream& operator<<(ostream &output,Matrix<T> &mat){
  output<<"Number of rows: "<<mat.get_rows()<<endl;
  output<<"Number of columns: "<<mat.get_cols()<<endl;
  for(unsigned int i = 1; i < mat.get_rows()+1;i++){
      output<<"[ ";
    for(unsigned int j = 1; j < mat.get_cols()+1;j++){
      output<<mat(i,j)<<" ";
    }
    output<<"]"<<"\n";
  }
  return output;
}

template <class T>
Matrix<T>& operator>>(istream &input, Matrix<T> &mat){
  string is;
  input>>is;
  //regex matrix("^\\(\\d+\\,\\d+\\,\\d+\\,\\d+\\,\\d+\\,\\d+\\)$");

  string row, col, number;
  int rows, cols, numbers;

  row = is.substr(1,1);
  col = is.substr(3,1);
  rows = stoi(row);
  cols = stoi(col);
  
  mat.set_rows(rows);
  mat.set_cols(cols);
  mat.set_capacity(rows,cols);
  for(unsigned int i = 0; i < rows; i++){
    for(unsigned int j = 0; j < cols; j++){
      number = is.substr(5+2*(i*cols+j),1);
      numbers = stoi(number);
      mat(i+1,j+1) = numbers;
    }
  }
  cout<<mat;
  return mat;
}

/*
int main(){
  
  Matrix<int> a = {1,2,3,4,5,6,7,8,9};
  cout<<a(1,1)<<endl;
  a.insert_row(1);
  cout<<a(1,1)<<endl;
  cout<<a.get_capacity()<<endl;
  a.remove_row(1);
  cout<<a(1,1)<<endl;
  
  Matrix<int> b = {1,2,3,4,5,6,7,8,9};
  b.append_row(1);
  cout<<b(2,1)<<endl;
  cout<<b.get_capacity()<<endl;
  
  Matrix<int> c = {1,2,3,4,5,6,7,8,9};
  c.insert_cols(2);
  cout<<c(1,2)<<endl;
  cout<<c.get_capacity()<<endl;
  c.remove_cols(2);
  cout<<c(1,2)<<endl;

  Matrix<int> d = {1,2,3,4,5,6,7,8,9};
  d.append_cols(1);
  cout<<d(1,2)<<endl;
  cout<<d.get_capacity()<<endl;

  c = d;
  c +=d;
  
  Matrix<int> t1 = {1,2,3,4,5,6,7,8,9};
  Matrix<int> t2 = {1,2,3,4,5,6,7,8,9};
  Matrix<int> f = t1 + t2;
  Matrix<int> g = t1 + 2;
  Matrix<int> h = t1 - t2;
  Matrix<int> i = t1 - 2;
  Matrix<int> j = t1 * t2;
  Matrix<int> k = t1 * 2;
  cout<<k.begin()<<endl;
  cout<<k.end()<<endl;
}
*/
