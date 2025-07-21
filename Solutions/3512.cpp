// 3512. Minimum Operations to Make Array Sum Divisible by K

#include <vector>
#include <numeric>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int minOperations(std::vector<int>& nums, int k) {
          return std::accumulate(begin(nums), end(nums),0) % k;
     }
};