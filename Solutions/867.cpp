// 867. Transpose Matrix

#include <vector>

// TIME COMPLEXITY : O(M*N)
// SPACE COMPLEXITY: O(M*N)

class Solution {
public:
     std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {

          auto m{ matrix.size() }, n{ matrix[0].size() };
          std::vector<std::vector<int>> t(n, std::vector<int>(m));

          for (size_t i{ 0 }; i < m; ++i)
               for (size_t j{ 0 }; j < n; ++i)
                    t[j][i] = matrix[i][j];

          return t;
     }
};