// 2006. Count Number of Pairs With Absolute Difference K

#include <vector>


// Here the input is in range [1,200] we can brute force it

class Solution {
public:
     int countKDifference(std::vector<int>& nums, int k) {

          int count{ 0 };
          int n = nums.size();
          for (int i{ 0 }; i < n; ++i)
               for (int j{ i + 1 }; j < n; ++j)
                    if (std::abs(nums[i] - nums[j]) == k) ++count;
               
          return count;
     }
};