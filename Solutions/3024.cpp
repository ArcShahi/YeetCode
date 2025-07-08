// 3024. Type of Triangle

#include <string>
#include <vector>
#include <algorithm>


class Solution {
public:
     std::string triangleType(std::vector<int>& nums) {

          std::ranges::sort(nums);

          if (!(nums[0] + nums[1] > nums[2])) return "none";

          if (nums[0] == nums[2])
               return "equilateral";
          else if (nums[0] == nums[1] || nums[1] == nums[2])
               return "isosceles";
          else
               return "scalene";
     }
};