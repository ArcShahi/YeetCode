// 441. Arranging Coins

#include <cmath>

// k(k+1)/2<=n; then k = (sqrt(8n+1)- 1)/2

// TIME COMPLEXITY : O(1)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int arrangeCoins(int n) {
          return static_cast<int>(std::floor((std::sqrt(8.0 * n + 1) - 1) / 2));
     }
};


class Solution {
public:
     int arrangeCoins(int n) {

          int count{ 0 };
          for (int i{ 1 }; i <= n; ++i)
          {
               if (0 <= n - i) ++count;
               else break;
               n -= i;
          }
          return count;
     }
};