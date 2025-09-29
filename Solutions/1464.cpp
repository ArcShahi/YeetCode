// 1464. Maximum Product of Two Elements in an Array

#include <vector>
#include <algorithm>


// TIME COMPLEXITY : O(NlogN)
// SPACE COMPLEIXTY : O(1);

class Solution {
public:
     int maxProduct(std::vector<int>& nums) {
          std::ranges::sort(nums);
          int n = nums.size();
          return (nums[n - 1] - 1) * (nums[n - 2] - 1);
     }
};


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int maxProduct(std::vector<int>& nums) {
         
          int f{ -1111 }, s{ -1111 };

          for (const auto& i : nums)
          {
               if (f < i)
               {
                    s = f;
                    f = i;
               }
               else if (s < i)
                    s = i;
          }

          return (f - 1) * (s - 1);
     }
};