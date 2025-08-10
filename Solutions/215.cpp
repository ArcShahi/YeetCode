// 215. Kth Largest Element in an Array

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(nlogn)
// SPACE COMPLEXITY : O(1)

// TODO : WITHOUT SORTING

class Solution {
public:
     int findKthLargest(std::vector<int>& nums, int k) {

          std::sort(rbegin(nums), rend(nums));
          return nums[k - 1];
     }
};