#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
 private:
  double real, imaginary;

 public:
  Complex();
  Complex(double real);
  Complex(double real,double imaginary);
  Complex(const Complex &c);

  double real();
  double imag();
  Complex& operator=(const Complex& c);
  Complex& operator+=(const Complex& c);
  Complex& operator-=(const Complex& c);
  Complex& operator*=(const Complex& c);
  Complex& operator/=(const Complex& c);
};

Complex operator""_i(unsigned long long arg);
Complex operator""_i(long double arg);
Complex operator+(Complex a, Complex const &b);
Complex operator-(Complex a, Complex const &b);
Complex operator*(Complex a, Complex const &b);
Complex operator/(Complex a, Complex const &b);
bool operator==(Complex &a, Complex &b);
bool operator!=(Complex &a, Complex &b);
double real(Complex &a);
double imag(Complex &a);
double abs(Complex &a);
std::ostream &operator<<(std::ostream &os, Complex &a);
Complex operator>>(std::isream &is, Complex &a);
#endif
  
