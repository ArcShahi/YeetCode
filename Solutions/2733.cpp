// 2733. Neither Minimum nor Maximum

#include <vector>
#include <algorithm>

class Solution {
public:
     int findNonMinOrMax(std::vector<int>& nums) {

          if (nums.size() < 3) return -1;

          std::sort(nums.begin(), nums.begin() + 3);

          return nums[1];
     }
};