#include<cxxtest/TestSuite.h>
#include "count_if_followed_by.h"

class MyTestSuite : public CxxTest::TestSuite {
public:
  void test2() {
    char const data[2] = {'X','G'};
    int const result = count_if_followed_by(data,2,'X','G');

    TS_ASSERT_EQUALS(result,1);
  }

};
  
