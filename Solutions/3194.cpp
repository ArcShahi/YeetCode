// 3194. Minimum Average of Smallest and Largest Elements

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(NlogN)
//  SPACE COMPLEXITY : O(1)

class Solution {
public:
     double minimumAverage(std::vector<int>& nums) {

          double min{ 100 }; // Acts as initial min cuz 1<nums[i]<50
          const int n = nums.size();
          std::ranges::sort(nums);

          for (int i{ 0 }; i < n / 2; ++i)
               min = std::min(min, (nums[i] + nums[n - i - 1]) * 0.5);
          
          return min;
     }
};