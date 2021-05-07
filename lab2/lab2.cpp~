#include <string>
#include <cmath>
#include <regex>
#include <iostream>
#include <algorithm>

using namespace std;

class Complex{
private:
  double re, im;
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

Complex::Complex(){
  this->re = 0;
  this->im = 0;
}

Complex::Complex(double reell){
  this->re = reell;
  this->im = 0;
}

Complex::Complex(double reell, double bullshit){
  this->re = reell;
  this->im = bullshit;
}

Complex::Complex(const Complex& c){
  this->re = c.re;
  this->im = c.im;
}

double Complex::real(){
  return this->re;
}

double Complex::imag(){
  return this->im;
}

Complex& Complex::operator=(const Complex& c){
  this->re = c.re;
  this->im = c.im;
  return *this;
}

Complex& Complex::operator+=(const Complex& c){
  this->re +=c.re;
  this->im += c.im;
  return *this;
}

Complex& Complex::operator-=(const Complex& c){
  this->re -= c.re;
  this->im -= c.im;
  return *this;
}

Complex& Complex::operator*=(const Complex& c){
  this->re = this->re*c.re-this->im*c.im;
  this->im = this->re*c.im+this->im*c.re;
  return *this;
}

Complex& Complex::operator/=(const Complex& c){
  this->re = (this->re*c.re+this->im*c.im)/(c.re*c.re+c.im*c.im);
  this->im = (this->im*c.re-this->re*c.im)/(c.re*c.re+c.im*c.im);
  return *this;
}

Complex operator""_i(long double bullshit){
  return Complex(0,bullshit);
}

Complex operator""_i(unsigned long long bullshit){
  return Complex(0,bullshit);
}

double real(Complex& c){
  return c.real();
}

double imag(Complex& c){
  return c.imag();
}

Complex operator+(Complex a, Complex const& b){
  a +=b;
  return a;
}

Complex operator-(Complex a, Complex const& b){
  a -=b;
  return a;
}

Complex operator*(Complex a, Complex const& b){
  a *=b;
  return a;
}

Complex operator/(Complex a,Complex const& b){
  a /=b;
  return a;
}

bool operator==(Complex& a, Complex& b){
  return a.real()==b.real() && a.imag()==b.imag();
}

bool operator!=(Complex& a, Complex& b){
  return !(a==b);
}

double abs(Complex& c){
  return sqrt(c.real()*c.real()+c.imag()*c.imag());
}

ostream& operator<<(ostream& output,Complex &c){
  output <<"("<<c.real()<<","<<c.imag()<<")"<<endl;
  return output;
}

Complex operator>>(istream& input, Complex& c){
  string is;
  input>>is;
  regex number("^\\d+\\.\\d+$|^\\d+$");
  regex numberPar("^\\(\\d+\\)$|^\\(\\d+\\.\\d+\\)$");
  regex compPar("^\\(\\d+\\,\\d+\\)$|^\\(\\d+\\.\\d+,\\d+\\.\\d+\\)$|^\\(\\d+,\\d+\\.\\d+\\)$|^\\(\\d+\\.\\d+,\\d+\\)$");

  if(regex_match(is,number)){
    c = stod(is);
    return c;
  }
  else if(regex_match(is,numberPar)){
    c = stod(is.substr(1,-2));
    return c;
  }
  else if(regex_match(is,compPar)){
    string reell, bullshit;
    double r, i;
    reell = is.substr(1,is.find(",")-1);
    bullshit = is.substr(is.find(",")+1,-2);
    r = stod(reell);
    i = stod(bullshit);
    c = Complex(r,i);
    return c;
  }
  else{
    return c;
  }
}

