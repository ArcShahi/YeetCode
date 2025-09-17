// 2483. Minimum Penalty for a Shop

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPELXITY : O(1)
class Solution {
public:
     int bestClosingTime(std::string customers) {

          int min{ 0 }, cur{ 0 }, hour{ 0 };

          for (int i{ 0 }; i < customers.length(); ++i)
          {
               char c{ customers[i] };

               cur += c == 'Y' ? -1 : 1;

               if (cur < min)
               {
                    hour = i + 1;
                    min = cur;
               }
          }
          return hour;
     }
};