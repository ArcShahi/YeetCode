// 3151. Special Array I

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     bool isArraySpecial(std::vector<int>& nums) {

          auto same_parity = [](int a, int b) {return (a & 1) == (b & 1); };
          return std::ranges::adjacent_find(nums, same_parity) == end(nums);
     }

};

class Solution {
public:
     bool isArraySpecial(std::vector<int>& nums) {
          
          for (size_t i = 1; i < nums.size(); i++)
               if ((nums[i - 1] % 2) == (nums[i] % 2))
                    return false;

          return true;
     }
     
};

