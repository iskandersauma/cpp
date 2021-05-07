#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;

class WaterManager{
 public:
  //unsigned int hyenasInside = 0;
  //unsigned int gnusInside = 0;
  atomic<int> hyenasInside = {0};
  atomic<int> gnusInside = {0};
  mutex m;
  condition_variable cond;
  void hyenaEnters();
  void hyenaLeaves();
  void gnuEnters();
  void gnuLeaves();
};
