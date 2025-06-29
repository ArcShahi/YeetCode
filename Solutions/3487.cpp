// 3487. Maximum Unique Subarray Sum After Deletion
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

// TIME COMPLEXITY :O(n)
// SPACE COMPLEXITY :O(n)

class Solution {
public:
     int maxSum(std::vector<int>& nums) {
 
          if (auto max_val{ *std::ranges::max_element(nums) }; max_val < 0)
               return max_val;

          std::unordered_set<int> set{};
          for (const auto& i : nums)
               if (i >= 0) set.insert(i);

          return std::accumulate(begin(set), end(set), 0);
     
     }
};