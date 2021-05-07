#include "bintree.cpp"
#include <cxxtest/TestSuite.h>

class MyTestSuite: public CxxTest::TestSuite{
public:
  void test0(){
    Node* p = nullptr;
    TS_ASSERT_EQUALS(find(p,0),"does not exist");
  }
  void test1(){
    Node * p = nullptr;
    insert(p,3,3.1);
    insert(p,2,0.5);
    insert(p, 1 , 0.2);
    insert(p, 5 , 5.5);

    TS_ASSERT_EQUALS(find(p,2),0.5);
  }
  void test2(){
    Node * p = nullptr;
    insert(p,3,3.1);
    insert(p,2,0.5);
    insert(p, 1 , 0.2);
    insert(p, 5 , 5.5);

    TS_ASSERT_EQUALS(max_height(p),3);
    TS_ASSERT_EQUALS(min_height(p),2);
    TS_ASSERT_EQUALS(is_balanced(p),true);
  }
  void test3(){
    Node * p = nullptr;
    insert(p,3,3.1);
    insert(p,2,0.5);
    insert(p, 1 , 0.2);
    insert(p, 5 , 5.5);
    TS_ASSERT_EQUALS(size(p),4);
    TS_ASSERT_EQUALS(find(p,3),3.1);
    edit(p,3)=0.001;
    TS_ASSERT_EQUALS(find(p,3),0.001);
  }

  void test4(){
    Node * p = nullptr;
    insert(p,3,3.1);
    insert(p,2,0.5);
    insert(p, 1 , 0.2);
    insert(p, 5 , 5.5);
    TS_ASSERT_EQUALS(size(p),4);
    remove(p,3);
    TS_ASSERT_EQUALS(size(p),3);
  }


};
