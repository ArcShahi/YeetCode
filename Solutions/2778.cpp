// 2778. Sum of Squares of Special Elements 

#include <vector>
#include <ranges>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int sumOfSquares(std::vector<int>& nums) {
          int sum{ 0 };
          const int n = nums.size();

          for (int i = 0; i < n; ++i)
               if (n % (i+1) == 0) 
                    sum += nums[i] * nums[i];
               
          return sum;
     }
};
