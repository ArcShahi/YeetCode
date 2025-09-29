// 2465. Number of Distinct Averages

#include <vector>
#include <algorithm>
#include <unordered_set>


// TIME COMPLEXITY : O(NlogN)
// SPACE COMPLEXITY : O(N)


class Solution {
public:
     int distinctAverages(std::vector<int>& nums) {

          const int n = nums.size();
          std::ranges::sort(nums);
          std::unordered_set<double> seen{};

          for (int i{ 0 }; i < n / 2; ++i)
          {
               double cur = (nums[i] + nums[n - i - 1]) * 0.5;
               seen.insert(cur);
          }
          
          return seen.size();
     }
};