// 34. Find First and Last Position of Element in Sorted Array

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(logN)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     std::vector<int> searchRange(std::vector<int>& nums, int target) {

          std::vector<int> rng{ -1,-1 };

          if (nums.empty()) return rng;
          auto l{ std::lower_bound(begin(nums),end(nums),target) };
          auto u{ std::upper_bound(begin(nums),end(nums),target) };

          if (l == end(nums) || *l!=target) return rng;

          rng[0] = std::distance(begin(nums), l);
          rng[1] = std::distance(begin(nums), std::prev(u));

          return rng;

     }
};