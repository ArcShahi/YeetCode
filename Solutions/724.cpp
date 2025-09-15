// 724. Find Pivot Index

#include <vector>
#include <numeric>
#include <iterator>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int pivotIndex(std::vector<int>& nums) {

          int sum{ std::accumulate(begin(nums),end(nums),0) };
          int left{ 0 };

          for (int i{ 0 }; i < nums.size(); ++i)
          {
               int right{ sum - left - nums[i] };
               if (right == left) return i;

               left += nums[i];
          }
          return -1;
     }
};
