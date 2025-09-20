// 503. Next Greater Element II

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::vector<int> nextGreaterElements(std::vector<int>& nums) {

          const auto n{ nums.size() };

          std::vector<int> out(n, -1);
          std::vector<int> stk{}; 

          for (size_t i = 0; i < 2*n; ++i)
          {
               auto idx{ i % n };
               while (!stk.empty() && nums[idx]>nums[stk.back()])
               {
                    out[stk.back()] = nums[idx];
                    stk.pop_back();
               }
               if (i < n) stk.push_back(i);
          }
     }
};