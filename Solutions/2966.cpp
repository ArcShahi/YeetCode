// 2966. Divide Array Into Arrays With Max Difference

#include <vector>
#include <algorithm>

// TIME COMPLXITY : O(nlogn)
// SPACE COMPLEXITY :O(n)
class Solution {
public:
     std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k)
     {
          std::ranges::sort(nums);
          std::vector<std::vector<int>> vec{};
          vec.reserve(nums.size() / 3);

          for (int i{ 0 }; i < nums.size(); i+=3){    
               if (k < nums[i + 2] - nums[i]) return {};
               vec.push_back({ nums[i],nums[i + 1],nums[i + 2] });
          }
          return vec;
     }
};