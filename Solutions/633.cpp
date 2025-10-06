// 633. Sum of Square Numbers

#include <cmath>

// TIME COMPLEXITY : O(sqrt(N))
// SPACE COMPLEXITY: O(1)


class Solution {
public:
     bool judgeSquareSum(int c) {

          for (long a = 0, b = std::sqrt(c); a <= b;)
          {
               if (auto val = a * a + b * b; val == c) return true;
               else if (val < c) ++a;
               else --b;
          }
          return false;
     }
};