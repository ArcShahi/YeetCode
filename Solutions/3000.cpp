// 3000. Maximum Area of Longest Diagonal Rectangle

#include <vector>
#include <cmath>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {

          double max_diagonal{ -1 };
          int max_area{ -1 };

          for (const auto& rect : dimensions)
          {
               double diagonal{ std::sqrt(rect[0] * rect[0] + rect[1] * rect[1]) };
               int area{ rect[0] * rect[1] };
               if (max_diagonal < diagonal)
               {
                    max_diagonal = diagonal;
                    max_area = area;
               }
               else if (std::abs(diagonal - max_diagonal) < 1e-9)
                    max_area = std::max(max_area, area);
          }
          return max_area;
     }     
};
