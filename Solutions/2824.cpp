// 2824. Count Pairs Whose Sum is Less than Target

#include <vector>

// TIME COMPLEXITY : O(n^2)
// SPACE COMPLEXITY : O(1)

// The nums.size() is sure to be in [1,50] , so just brute force

class Solution {
public:
     int countPairs(std::vector<int>& nums, int target) {


          int count{ 0 };
          //0 <= i < j < n and nums[i] + nums[j] < target.
          for (int i{ 0 }; i < nums.size() - 1; ++i)
          {
               for (int j{ i + 1 }; j < nums.size(); ++j)
               {
                    if (nums[i] + nums[j] < target) ++count;
               }
          }

          return count;
     }
};