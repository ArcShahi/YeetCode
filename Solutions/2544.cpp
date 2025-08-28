// 2544. Alternating Digit Sum

#include <string>

// TIME COMPLEXITY: O(logN)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int alternateDigitSum(int n) {

          int sum{ 0 };
          int sign{ 1 };
         
          for (; n; sign = -sign, n /= 10)
          {
               int dig{ n % 10 };
               sum += sign * dig;
          }
          return -sign * sum;
     }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)


class Solution {
public:
     int alternateDigitSum(int n) {

          auto num{ std::to_string(n) };
          auto flag{ false };

          int sum{ 0 };
          for (const auto digit : num)
          {
               sum = flag ? sum - (digit - '0') : sum + (digit - '0');
               flag = !flag;
          }
          return sum;
     }
};