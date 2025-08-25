// 2656. Maximum Sum With Exactly K Elements 

#include <vector>
#include <numeric>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)


class Solution {
public:
     int maximizeSum(std::vector<int>& nums, int k) {
          
          int max{ *std::ranges::max_element(nums)};
          int n{ max + k - 1 };
          int m{ max - 1 };

          return (n * (n + 1) / 2) - (m * (m + 1) / 2);        
     }
};