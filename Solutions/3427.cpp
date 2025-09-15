// 3427. Sum of Variable Length Subarrays

#include <vector>

// TIME COMPLEXITY : O(N^2) : input in [1,100] 
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int subarraySum(std::vector<int>& nums) {

          int sum{ 0 };
          for (int i{ 0 }; i < nums.size(); ++i)
               for (int j{ std::max(0,i - nums[i]) }; j <= i; ++j)
                    sum += nums[j];
    
          return sum;
     }
};