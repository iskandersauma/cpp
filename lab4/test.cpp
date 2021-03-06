#include "matrix.cpp"
#include <cxxtest/TestSuite.h>

class MyTestSuite: public CxxTest:: TestSuite{
public:
  void test_insert(){
    Matrix<int> a = {1,2,3,4,5,6,7,8,9};
    a.insert_row(1);
    TS_ASSERT_EQUALS(a(1,1),0);
    a.insert_cols(2);
    TS_ASSERT_EQUALS(a(1,2),0);
  }

  void test_append(){
    Matrix<int> b = {1,2,3,4,5,6,7,8,9};
    b.append_row(1);
    TS_ASSERT_EQUALS(b(2,1),0);
  }

  void test_remove(){
    Matrix<int> c = {1,2,3,4,5,6,7,8,9};
    c.remove_row(2);
    TS_ASSERT_EQUALS(c(2,1),7)
  }

    void test_get(){
    Matrix<int> d = {1,2,3,4,5,6,7,8,9};
    TS_ASSERT_EQUALS(d.get_rows(),3);
    TS_ASSERT_EQUALS(d.get_cols(),3);
    TS_ASSERT_EQUALS(d.get_capacity(),9)
  }

  void test_add(){
    Matrix<int> e = {1,2,3,4,5,6,7,8,9};
    Matrix<int> f = {1,2,3,4,5,6,7,8,9};
    Matrix<int> g(3);
    e +=f;
    g = e+f;
    TS_ASSERT_EQUALS(e(3,3),18);
    TS_ASSERT_EQUALS(g(1,1),3);
  }

  void test_subtract(){
    Matrix<int> a = {1,2,3,4,5,6,7,8,9};
    Matrix<int> b = {1,2,3,4,5,6,7,8,9};
    Matrix<int> d = {1,2,3,4,5,6,7,8,9};
    Matrix<int> c(3);
    b -=a;
    c = d-a;
    TS_ASSERT_EQUALS(b(2,2),0);
    TS_ASSERT_EQUALS(c(2,2),0);
  }

  void test_multi(){
    Matrix<int> a = {1,2,3,4,5,6,7,8,9};
    Matrix<int> b = {1,2,3,4,5,6,7,8,9};
    Matrix<int> d = {1,2,3,4,5,6,7,8,9};
    Matrix<int> f;
    Matrix<int> c(3);
    cout<<c<<endl;
    b *=a;
    c = d*a;
    TS_ASSERT_EQUALS(b(1,2),4);
    TS_ASSERT_EQUALS(c(2,2),25);
  }

  void test_cout_cin(){
    Matrix<int> a = {1,2,3,4,5,6,7,8,9};
    cout<<a;
    Matrix<int> b(2);
    cin>>b;
    TS_ASSERT_EQUALS(b(1,1),1);
  }

  void test_constructor(){
    Matrix<int> a(3);
    TS_ASSERT_EQUALS(a(1,1),0);
    Matrix<int> b = {1,2,3,4,5,6,7,8,9};
    a = b;
    TS_ASSERT_EQUALS(a(1,1),1);
    TS_ASSERT_EQUALS(b(1,1),1);
    Matrix<int> c = Matrix<int>();
    //~c;
  }
};
