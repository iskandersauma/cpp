#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <initializer_list>
#include <iostream>
using namespace std;

template <class T>
class Matrix{
 public:

  //constructors
  Matrix(); //done
  Matrix(const T size); //done
  Matrix(unsigned rows); //done
  Matrix(unsigned rows, unsigned cols); //done
  Matrix(Matrix &obj); //done
  Matrix(Matrix &&obj); //done
  Matrix(initializer_list<T> l); // done
  ~Matrix();  //done
  //operators
  void operator=(Matrix &obj); //done
  T& operator()(unsigned int row, unsigned int col); //done
  Matrix& operator= (Matrix &&obj); //done
  void operator+= (Matrix &mat); //done
  void operator+= (const T number); //done
  void operator-= (Matrix &mat); //done
  void operator-= (const T number); //done
  void operator*= (Matrix &mat); //done
  void operator*= (const T number); //done
  bool operator== (Matrix &mat); //done

  //glöm ej!!! att göra operatorer utan likamed tecken
  //also done!

  //methods
  void reset(); //done
  void set_rows(T rows);  //done
  void set_cols(T cols);  //done
  void set_capacity(T rows); //done
  void set_capacity(T rows, T cols); //done
  size_t get_rows(); //done
  size_t get_cols(); //done
  size_t get_capacity(); //done
  void insert_row(unsigned int row); //done
  void insert_cols(unsigned int cols); //done
  void append_row(unsigned int row); //done 
  void append_cols(unsigned int cols); //done
  void remove_row(unsigned int row); //done
  void remove_cols(unsigned int cols); //done
  T* begin(); //done
  T* end();  //done
  
 private:
  size_t m_rows;
  size_t m_cols;
  size_t m_capacity;
  T* m_vec;

};

#endif
