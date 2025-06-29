// 1470. Shuffle the Array

#include <vector>
#include <iostream>

// TIME COMPLEXITY : O(n);
// SPACE COMPLEXITY : O(1);


// IO slow down the runtime

auto fast_io = []() {
     std::ios::sync_with_stdio(false);
     std::cin.tie(nullptr);
     return 0;
     }();

class Solution {
public:
     std::vector<int> shuffle(std::vector<int>& nums, int n) 
     {
         
          std::vector<int> vec{};
          vec.reserve(2*n);

          for (int i{ 0 }; i < n; ++i)
          {
               vec.push_back(nums[i]);
               vec.push_back(nums[i + n]);
          }

          return vec;
     }
};