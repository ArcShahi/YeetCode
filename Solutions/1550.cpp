// 1550. Three Consecutive Odds

#include <vector>

class Solution {
public:
     bool threeConsecutiveOdds(std::vector<int>& arr) {

          int odd{ 0 };
          int max_odd{ 0 };

          for (const auto& i : arr)
          {
               if (i & 1)
               {
                    ++odd;
               }
               else
               {
                    odd = 0;
               }
               max_odd = std::max(max_odd, odd);
          }

          return max_odd >= 3;
     }
};