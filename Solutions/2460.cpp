// 2460. Apply Operations to an Array

#include <vector>
#include <algorithm>

class Solution {
public:
     std::vector<int> applyOperations(std::vector<int>& nums) {

          int n = nums.size();

          for (int i{ 0 }; i < n-1; ++i)
          {
               if (nums[i] == nums[i + 1])
               {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
               }
          }

          // Move zeros to end
          int itr{ 0 };

          for (auto& i : nums) {
               if (i) nums[itr++] = i;
          }

          // Fill everything with 0s
          while (itr<n)
          {
               nums[itr++] = 0;
          }
          return nums;
     }
};

