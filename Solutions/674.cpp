// 674. Longest Continuous Increasing Subsequence

#include <vector>

class Solution {
public:
     int findLengthOfLCIS(std::vector<int>& nums) {

          if (nums.empty()) return 0;

          int cache{ 1 };
          int count{ 1 };

          for (int i{ 1 }; i < nums.size(); ++i)
          {
               if (nums[i - 1] < nums[i])
                    ++cache;
               else
                    cache = 1;

               count = std::max(cache, count);

          }

          return count;
     }
};

