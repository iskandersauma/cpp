#include <iostream>

using namespace std;


template <int p, int i>
struct check_if_prime
{
  static const bool prime = (p % i != 0) && check_if_prime<p,i-1>::prime;
};

template <int p>
struct check_if_prime<p,2>
{
  static const bool prime = (p % 2 != 0);
};

template <unsigned int x>
struct is_prime
{
  static const bool prime = check_if_prime<x,x-1>::prime; 
};

template<>
struct is_prime<2>
{
  static const bool prime = true;
};

int main()
{
  cout << is_prime<5>::prime << endl;
  cout<<is_prime<6>::prime<<endl;
}
