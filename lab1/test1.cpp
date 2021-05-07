#include <cxxtest/TestSuite.h>

#include "count_if_followed_by.h"

class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1 () {
      char const  data[4] = {'G','G','X','G'};
      int  const   result = count_if_followed_by (data, 3, 'X', 'G');

      //expected: result == 0
      //outcome: result == 1

      TS_ASSERT_EQUALS(result, 1);
    }
  

};
