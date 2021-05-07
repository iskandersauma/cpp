#include <cxxtest/TestSuite.h>
#include "lab2.cpp"

class MyTestSuite: public CxxTest::TestSuite{
public:
  void test1(){
    Complex C1(6.0,3.0);
    Complex C2(3.5,2.5);
    C1 *=C2;
    TS_ASSERT_EQUALS(real(C1),13.5);
  }
  void test2(){
    Complex C3(6.0,6.0);
    C3 = C3/6;
    TS_ASSERT_EQUALS(real(C3),1.0);
  }

  void test3(){
    Complex C4(1.0,1.0);
    Complex C5(1.0,1.0);
    C5 = C4+C4+1+5;
    TS_ASSERT_EQUALS(real(C5),8.0);
  }

  void test4(){
    Complex C6(1.0,1.0);
    Complex C7(2.0,2.0);
    C7 +=C6 +=4;
    TS_ASSERT_EQUALS(real(C7),7.0);
    TS_ASSERT_EQUALS(imag(C7),3.0);
  }

  void test5(){
    Complex d1(0.0,0.0);
    d1 = 3+5_i;
    TS_ASSERT_EQUALS(real(d1),3.0);
    TS_ASSERT_EQUALS(imag(d1),5.0);
  }

  void test6(){
    Complex d2(6.0,6.0);
    Complex d3(6.0,6.0);
    TS_ASSERT_EQUALS(d2==d3, true)
  }
};
