
// 287. Find the Duplicate Number

#include <vector>
#include <iostream>

class Solution
{
public:
     Solution()
     {
          std::ios::sync_with_stdio(0);
          std::cin.tie(0);
     }

public:
     int findDuplicate(const std::vector<int>& nums)
     {
          int slow{ nums[0] };
          int fast{ nums[0] };

          // Phase 1: Detect cycle
          do
          {
               slow = nums[slow];
               fast = nums[nums[fast]];
          } while (slow != fast);

          // Phase 2: Find entry point of cycle 
          slow = nums[0];
          while (slow != fast)
          {
               slow = nums[slow];
               fast = nums[fast];
          }

          return slow;
     }
};

