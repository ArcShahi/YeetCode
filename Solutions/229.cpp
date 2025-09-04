// 229. Majority Element II

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)


class Solution {
public:
     std::vector<int> majorityElement(std::vector<int>& nums) {

          int c1{}, m1{};
          int c2{}, m2{};


          for (const auto& num : nums)
          {
               if (num == m1) ++c1;
               else if (num == m2) ++c2;
               else if (!c1) m1 = num, c1 = 1;
               else if (!c2) m2 = num, c2 = 1;
               else --c1, --c2;
          }

          // Second Pass to verify canidate

          c1 = c2 = 0;
          for (const auto& num : nums)
          {
               if (num == m1) ++c1;
               else if (num == m2) ++c2;
          }
          int n = nums.size();

          std::vector<int> majority{};
          if (c1 > (n / 3)) majority.push_back(m1);
          if (c2 > (n / 3)) majority.push_back(m2);

          return majority;
     }
	
};