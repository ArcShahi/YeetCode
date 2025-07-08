// 75. Sort Colors

#include <vector>
#include <algorithm>

// Dutch national flag problem (DNF )

class Solution {
public:
     void sortColors(std::vector<int>& nums) {

          auto l{ begin(nums) };
          auto r{ end(nums) - 1 };
          auto mid{ (begin(nums)) };

          while (mid<=r)
          {
               if (*mid == 0)
               {
                    std::iter_swap(l++, mid++);
               }
               else if (*mid == 2)
               {
                    std::iter_swap(mid, r--);
               }
               else
               {
                    ++mid;
               }

          }
         
     }
};

