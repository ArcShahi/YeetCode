// 3232. Find if Digit Game Can Be Won

#include <vector>


class Solution {
public:
     bool canAliceWin(std::vector<int>& nums)
     {
          int x1{};
          int x2{};
          for (const auto& i : nums)
          {
               if (i < 10)
               {
                    x1 +=i;
               }
               else
               {
                    x2 += i;
               }
          }
          return  !(x1 = x2);
     }
};