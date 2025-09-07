// 1304. Find N Unique Integers Sum up to Zero

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N) , O(1) If ignored return value

class Solution {
public:
     std::vector<int> sumZero(int n) {

          std::vector<int> sum{};
          sum.reserve(n);

          for (int i{ 1 }; i <= n / 2; ++i)
          {
               sum.push_back(i);
               sum.push_back(-i);
          }

          if (n & 1) sum.push_back(0);
          return sum;
     }
};