// 2574. Left and Right Sum Differences

#include <vector>
#include <numeric>

// TIME COMPELXITY : O(N)
// SPACE COMPLEXITY : O(1) ; if ignoring return value

class Solution {
public:
     std::vector<int> leftRightDifference(std::vector<int>& nums) {

          int n = nums.size();
          std::vector<int> diff(n);

          int sum{ std::accumulate(begin(nums),end(nums),0) };
          int left{ 0 };
          for (int i{ 0 }; i < n; ++i)
          {
               int right{ sum - left - nums[i] };
               diff[i] = abs(right - left);
               left += nums[i];
          }
          return diff;
     }
};