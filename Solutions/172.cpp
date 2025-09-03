// 172. Factorial Trailing Zeroes

// TIME COMPLEXITY : O(logN)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int trailingZeroes(int n) {

          // Legendre's formula
          int exp{ 0 };
          for (int d{ 5 }; d <= n; d *= 5) exp += (n / d);
          return exp;
     }
};