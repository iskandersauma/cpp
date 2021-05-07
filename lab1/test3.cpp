#include<cxxtest/TestSuite.h>
#include "count_if_followed_by.h"

class MyTestSuite : public CxxTest::TestSuite {
public:
  void test3() {
    char const data[10] = {'G','G','X','X','X','G','G','G','G','X'};
    int const result = count_if_followed_by(data,10,'G','X');

    TS_ASSERT_EQUALS(result,3);
  }
};
