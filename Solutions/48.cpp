
// Rotate Image
#include <vector>
#include <algorithm>

class Solution {
public:
     void rotate(std::vector<std::vector<int>>& matrix) {

          auto n = matrix.size();

          // Transpose
          for (int i{ 0 }; i < n; ++i)
               for (int j{ i + 1 }; j < n; ++j)
                    std::swap(matrix[i][j], matrix[j][i]);
        
          // Flip
          for (auto& i : matrix)
               std::ranges::reverse(i);
          
     }
};