// 2149. Rearrange Array Elements by Sign

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::vector<int> rearrangeArray(std::vector<int>& nums) {

          std::vector<int> re(nums.size(), 0);

          int p{ 0 }, n{ 1 };

          for (const auto& i : nums)
          {
               if (i > 0) {
                    re[p] = i;
                    p += 2;
               }
               else
               {
                    re[n] = i;
                    n += 2;
               }
          }
          return re;
     }
};