// 2974. Minimum Number Game

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(NlogN)
// SPACE COMPLEXITY : O(1)

// SORT and Swap Adjacent elements

class Solution {
public:
     std::vector<int> numberGame(std::vector<int>& nums) {

          std::sort(begin(nums), end(nums));
          for (size_t i{ 0 }; i < nums.size(); i+=2)
               std::swap(nums[i], nums[i + 1]);

          return nums;
     }
};