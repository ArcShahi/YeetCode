// 2485. Find the Pivot Integer

#include <cmath>

// TIME COMPLEXITY : O(log(N))
// SPACE  COMPLEXITY :O(1)

// The  Sum of Arithmetic sequence from (1 to x ) should equal ( x to n )

class Solution {
public:
     int pivotInteger(int n) {

          int sum{ n * (n + 1) / 2 };
          double p{ std::sqrt(sum) };
          return p - std::ceil(p) == 0 ? static_cast<int>(p) : -1;
     }
};


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int pivotInteger(int n) {

          int sum{ n * (n + 1) / 2 };

          int left{ 0 };
          for (int i{ 1 }; i <= n; ++i)
          {
               int right{ sum - left - i };
               if (left == right) return i;
               left += i;
          }
          return -1;
     }
};