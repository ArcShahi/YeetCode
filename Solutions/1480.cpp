// 1480. Running Sum of 1d Array

#include <vector>
#include <algorithm>
#include <numeric>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)


class Solution {
public:
     std::vector<int> runningSum(std::vector<int>& nums) {

          for (int i{ 1 }; i < nums.size(); ++i)
               nums[i] += nums[i - 1];

          return nums;
     }
};
