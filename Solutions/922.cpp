// Sort Array By Parity II

#include <vector>

class Solution {
public:
     std::vector<int> sortArrayByParityII(std::vector<int>& nums) {


          int even{ 0 };
          int odd{ 1 };

          while (even<nums.size())
          {
               if (!(nums[even] & 1)) even += 2;
               else if (nums[odd] & 1) odd += 2;
               else
               {
                    std::swap(nums[even], nums[odd]);
                    even += 2;
                    odd += 2;
               }
          }
         
          return nums;
     }
};
