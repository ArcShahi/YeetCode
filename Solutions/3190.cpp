// 3190. Find Minimum Operations to Make All Elements Divisible by Three

#include <vector>

// IGNORE THE NOISE... see the pattern

class Solution {
public:
     int minimumOperations(std::vector<int>& nums) {

          int count{ 0 };

          for (const auto& i : nums)
               if (i % 3!=0) ++count;

          return count;

     }
};