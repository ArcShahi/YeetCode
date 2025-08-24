// 3065. Minimum Operations to Exceed Threshold Value I

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int minOperations(std::vector<int>& nums, int k) {

          return std::ranges::count_if(nums, [&k](const int x) {return x < k; });
     }
};