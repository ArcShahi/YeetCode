// 3658. GCD of Odd and Even Sums

#include <numeric>

// TIME COMPLEXITY : O(Log(N^2));
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int gcdOfOddEvenSums(int n) {

          int even{ (n * n) + n };
          int odd = { n * n };
          return std::gcd(even, odd);
     }
};