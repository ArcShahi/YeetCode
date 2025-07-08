// 3264. Final Array State After K Multiplication Operations I

#include <vector>
#include <algorithm>

class Solution {
public:
     std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier)
     {
          
          for (int i{ 0 }; i < k; ++i)
          {
               auto itr = std::min_element(begin(nums), end(nums));
               *itr = *itr * multiplier;
          }
          return nums;
     }
};


// TIME COMPEXITY : O(k*n)
// SPACE COMPLEXITY : O(1)