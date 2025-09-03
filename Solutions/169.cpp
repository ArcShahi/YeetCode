// 169. Majority Element

#include <vector>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(1)

// Boyer–Moore majority vote algorithm 

class Solution {
public:
     int majorityElement(std::vector<int>& nums) {

          int m{}, count{ 0 };
          for (const auto& num : nums)
          {
               if (!count)
               {
                    m = num;
                    count = 1;
               }
               else if (m == num)++count;
               else --count;
          }

          return m;
     }
};
