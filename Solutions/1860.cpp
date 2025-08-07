// 1860. Incremental Memory Leak

#include <vector>

// TIME COMPLEXITY : O(sqrt(m1+m2))
// SPACE  COMPLEXITY : O(1)

class Solution {
public:
     std::vector<int> memLeak(int memory1, int memory2) {

          int sec{ 1 };
          while (sec<=memory1 || sec<=memory2)
          {
               if (memory2 <= memory1)
                    memory1 -= sec;
               else
                    memory2 -= sec;
               ++sec;
          }
          return { sec,memory1,memory2 };
     }
};
