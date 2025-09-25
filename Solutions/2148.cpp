// 2148. Count Elements With Strictly Smaller and Greater Elements 

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int countElements(std::vector<int>& nums) {

          const auto [min, max] = std::ranges::minmax_element(nums);      
          return std::ranges::count_if(nums, [&](int x) {return *min < x && x < *max; });
     }
};