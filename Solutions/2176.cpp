// 2176. Count Equal and Divisible Pairs in an Array

#include <vector>
// TIME COMPLEXITY : O(N*N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int countPairs(std::vector<int>& nums, int k) {
          
          int count{ 0 };
          const size_t n{ nums.size() };

          for (size_t i = 0; i < n; ++i)
               for (size_t j{ i+1 }; j < n; ++j)
                    if (nums[i] == nums[j] && (i * j) % k == 0) ++count;

          return count;         
     }
};
