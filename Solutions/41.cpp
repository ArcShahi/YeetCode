// 41. First Missing Positive

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE C0MPLXITY: O(1)

class Solution {
public:
     int firstMissingPositive(std::vector<int>& nums) {

          const int n = nums.size();

          // PREPROCESSING : Repalce every {0,Neg,n<} values with n+1
          for (auto& num : nums)
               if (num <= 0 || n < num)
                    num = n + 1;

          for (auto& num : nums)
          {
               int i=abs(num) - 1;
               if (0 <= i && i < n) nums[i] = -abs(nums[i]);
          }

          for (int i{ 0 }; i < n; ++i)
               if (nums[i] > 0) return i+1;
          
          return n+1;
     }
};