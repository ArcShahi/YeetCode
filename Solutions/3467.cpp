// 3467. Transform Array by Parity

#include <vector>
#include <algorithm>


// TIME COMPLEXITY O(n)
// SPACE COMPLEXITY 0(1)

class Solution {
public:
     std::vector<int> transformArray(std::vector<int>& nums)
     {
          auto l{ begin(nums) };
          auto r{ end(nums) - 1 };

          while (l<=r)
          {
               if (*l & 1)
               {    
                    *l = 1;
                    std::iter_swap(l, r--);        
               }
               else
               {
                    *l = 0;
                    ++l;
               }
          }
          return nums;

     }
};


// EASIER TO READ almost same RUNTIME

// TIME COMPLEXITY : O(nlogn)
// SPACE COMPLEXITY : 0(1)
class Solution2 {
public:
     std::vector<int> transformArray(std::vector<int>& nums)
     {
          for (auto& i : nums)
               i = (i & 1) ? 1 : 0;

          std::ranges::sort(nums);
          return nums;
     }
};
