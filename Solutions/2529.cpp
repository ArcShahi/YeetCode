// 2529. Maximum Count of Positive Integer and Negative Integer

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(logN)
// SPACE COMPLEXITY: O(1)


class Solution {
public:
     int maximumCount(std::vector<int>& nums) {

          auto l{ std::lower_bound(begin(nums),end(nums),0) };
          auto r{ std::upper_bound(begin(nums),end(nums),0) };

          auto pos{ std::distance(r,end(nums)) };
          auto neg{ std::distance(begin(nums),l)};

          return std::max(pos, neg);
     }
};

