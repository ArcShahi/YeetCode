// 566. Reshape the Matrix

#include <vector>


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1); Ignoring return value

class Solution {
public:
     std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, 
          int r, int c) 
     {
          int m = mat.size(), n = mat[0].size();
          if (m*n!=r*c) return mat;

          std::vector<std::vector<int>> rat(r, std::vector<int>(c));

          for (int k{ 0 }; k < m * n; ++k)
          {
               // In OG array
               int i{ k / n };
               int j{ k % n };

               // In output 
               int x{ k / c };
               int y{ k % c };

               rat[x][y] = mat[i][j];
          }

          return rat;
     }
};