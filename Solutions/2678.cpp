// 2678. Number of Senior Citizens

#include <vector>
#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int countSeniors(std::vector<std::string>& details) {

          int count{ 0 };
          for (const auto& str : details)
          {
               int age{ (str[11] - '0') * 10 + (str[12] - '0') };
               if (age > 60) ++count;
          }
          return count;
     }
};