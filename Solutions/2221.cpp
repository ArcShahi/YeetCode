// 2221. Find Triangular Sum of an Array

#include <vector>

// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     int triangularSum(std::vector<int>& nums) {
   
          std::vector<int> sum{ nums };
          for (int i=nums.size() - 1; i; --i)
               for (int j{ 0 }; j<i; ++j)
                    sum[j] = (sum[j] + sum[j + 1]) % 10;
                    
          return sum[0];
     }
};