// 3701. Compute Alternating Sum

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int alternatingSum(std::vector<int>& nums) {

          int even{ 0 }, odd{};

          for (int i{ 0 }; i < nums.size(); ++i)
          {
               if (i % 2 == 0) even += nums[i];
               else odd += nums[i];
          }

          return even - odd;
     }
};