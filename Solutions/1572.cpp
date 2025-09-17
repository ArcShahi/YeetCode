// 1572. Matrix Diagonal Sum

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int diagonalSum(std::vector<std::vector<int>>& mat) {

          int sum{ 0 };
          const size_t n{ mat.size() };

          for (size_t i = 0; i < n; ++i)
               sum += mat[i][i] + mat[n - i - 1][i];
          

          // if n is odd subtrct the middle element cuz it's added twice
          return  n & 1 ? sum -= mat[n / 2][n / 2] : sum;
     }
};