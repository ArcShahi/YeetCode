// 1913. Maximum Product Difference Between Two Pairs

#include <vector>
#include <algorithm>


// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int maxProductDifference(std::vector<int>& nums) {

          int min1{ INT32_MAX }, min2{ INT32_MAX };
          int max1{ INT32_MIN }, max2{ INT32_MIN };


          for (const auto& num : nums)
          {
               if (max1 < num)
               {
                    max2 = max1;
                    max1 = num;
               }
               else if (max2 < num) max2 = num;

               if (num < min1)
               {
                    min2 = min1;
                    min1 = num;
               }
               else if(num<min2) min2=num;
          }

          return max1 * max2 - min1 * min2;
     }
};



// TIME COMPLEXITY : O(NlogN)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int maxProductDifference(std::vector<int>& nums) {

          std::ranges::sort(nums);
          auto last{ end(nums) - 1 };
          return (*last--) * (*last) - (nums[0] * nums[1]); // ;)
     }
};

class Solution {
public:
     int maxProductDifference(std::vector<int>& nums) {

          std::ranges::sort(nums);
          auto n{ nums.size() - 1 };
          return nums[n] * nums[n - 1] - nums[0] * nums[1];
     }
};