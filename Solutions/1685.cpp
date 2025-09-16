// 1685. Sum of Absolute Differences in a Sorted Array

#include <vector>
#include <numeric>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1) 

class Solution {
public:
     std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {

          int total{ std::accumulate(begin(nums), end(nums), 0) };

          int n = nums.size();
          int leftsum{ 0 };

          for (int i{ 0 }; i < n; ++i)
          {
               int x{ nums[i] };
               int rightsum{ total - leftsum - x };
               nums[i] = x * i - leftsum + rightsum - x * (n - i - 1); // Formula for sum of diff
               leftsum += x;
          }

          return nums;
     }
};

// YOU CAN'T HAVE SOLVED THIS WITHOUT KNOWING THE FORMULA