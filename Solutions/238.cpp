// 238. Product of Array Except Self

#include <numeric>
#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     std::vector<int> productExceptSelf(std::vector<int>& nums) {

          int n = nums.size();

          std::vector<int> prod(n);
          prod[0] = 1;

          for (int i{ 1 }; i < n; ++i)
               prod[i] = prod[i - 1] * nums[i - 1];

          int right{ 1 };
          for (int i{ n - 1 }; i >= 0; --i)
          {
               prod[i] *= right;
               right *= nums[i];
          }
          return prod;
     }
};
