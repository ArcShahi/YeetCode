// 215. Kth Largest Element in an Array

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// TODO : WITHOUT SORTING

class Solution {
public:
     int findKthLargest(std::vector<int>& nums, int k) {

          auto nth{ begin(nums) + nums.size() - k};
          std::nth_element(begin(nums), nth, end(nums));
          return *nth;
         
     }
};