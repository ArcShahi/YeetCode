// 1017. Convert to Base -2

#include <string>
#include <bitset>

// TIME COMPLEXITY : O(logN)
// SPACE COMPLEXITY : O(1)


class Solution {
public:
     std::string baseNeg2(int n) {

          std::string neg{};

          while (n)
          {
               int rem{ n % -2 };
               n /= -2;

               if (rem < 0) {
                    rem += 2;
                    n += 1;
               }
               neg = char(rem + '0') + neg;
          }
          return neg;
     }
};
