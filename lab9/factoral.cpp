#include <iostream>

using namespace std;

template <int x>
struct Factorial
{
  static const int nr = x * Factorial<x - 1>::nr;
};

template <>
struct Factorial<1>
{
  static const int nr = 1;
};
int main()
{
  std::cout << Factorial<5>::nr << std::endl;
}
