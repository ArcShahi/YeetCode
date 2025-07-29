// 118. Pascal's Triangle

#include <vector>

// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY : O(N^2)

// Combanitorics formula for Pascal Triangle : current_row[j]=pvs_row[i-1][j-1]+pvs_row[i-1][j]

class Solution {
public:
     std::vector<std::vector<int>> generate(int rows) {

          if (rows == 1) return { {1} };
          std::vector<std::vector<int>> triangle{{1}};

          for (int i{1}; i < rows; ++i)
          {
               std::vector<int> v(i + 1, 1);
               for (int j{ 1 }; j < i; ++j) {
                    v[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
               }
               triangle.push_back(std::move(v));
          }
          return triangle;
     }
};