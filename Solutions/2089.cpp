// 2089. Find Target Indices After Sorting Array

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(NlogN)
// SPACE COMPLEXITY : O(1) , Ignoring return value

class Solution {
public:
     std::vector<int> targetIndices(std::vector<int>& nums, int target) {

          std::vector<int> idx{};
          std::ranges::sort(nums);

          for (size_t i{ 0 }; i < nums.size(); ++i)
               if (nums[i] == target) idx.push_back(i);

          return idx;
     }
};