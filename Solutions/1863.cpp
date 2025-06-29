// 1863. Sum of All Subset XOR Totals

#include <vector>
// TIME COMPLEXITY : O(n*2^n);
class Solution {
public:
     int subsetXORSum(std::vector<int>& nums) {
          int count{ 0 };

          int n = nums.size();
          int subset = 1 << n;

          for (int i{ 0 }; i < subset; ++i)
          {
               int tempxor = 0;
               for (int j{ 0 }; j < n; ++j)
               {
                    if (i & (1 << j))
                    {
                         tempxor ^= nums[j];
                    }
               }
               count += tempxor;
          }
          return count;

     }
};

