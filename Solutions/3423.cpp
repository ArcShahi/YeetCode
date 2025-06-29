// 3423. Maximum Difference Between Adjacent Elements in a Circular Array

#include <vector>
#include <algorithm>

class Solution {
public:
     int maxAdjacentDistance(std::vector<int>& nums) {

          int max_diff{ std::abs(nums.front()-nums.back())};

          for (int i{ 0 }; i < nums.size() - 1; ++i)
               max_diff = std::max(max_diff, std::abs(nums[i] - nums[i + 1]));

       
          return max_diff;
     }
};