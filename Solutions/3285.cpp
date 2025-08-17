// 3285. Find Indices of Stable Mountains

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(1)


class Solution {
public:
     std::vector<int> stableMountains(std::vector<int>& height, int threshold) {

          std::vector<int> stable{};
          for (int i{ 0 }; i < height.size() - 1; i++)
               if (threshold < height[i])
                    stable.push_back(i + 1);

          return stable;
     }
};