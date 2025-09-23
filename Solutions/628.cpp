// 628. Maximum Product of Three Numbers

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXTIY: O(1)

class Solution {
public:
     int maximumProduct(std::vector<int>& nums) {


          int f{ MIN }, s{ MIN }, t{ MIN };
          int x{ MAX }, y{ MAX };

          for (const auto& i : nums)
          {

               if (f < i)
               {
                    t = s;
                    s = f;
                    f = i;
               }
               else if (s < i)
               {
                    t = s;
                    s = i;
               }
               else if (t < i)
                    t = i;

               if (i < x)
               {
                    y = x;
                    x = i;
               }
               else if (i < y)
               {
                    y = i;
               }
          }
          return std::max(f * s * t, f * x * y);
     }

private:
     static constexpr int MAX{ 1111 };// works as initial max cuz 1<=nums[i]<=1000
     static constexpr int MIN{ -1111 };
};