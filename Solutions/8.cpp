// 8. String to Integer (atoi)

#include <string>
#include <string_view>
#include <cctype>      // for std::isdigit
#include <climits>     // for INT_MAX, INT_MIN
#include <cstdint>     // for uint8_t

// TIME COMPLXITY : O(n)

class Solution {
public:
     int myAtoi(std::string s) {

          std::string_view sv{ s };

          // Skip leading whitespace
          size_t i = sv.find_first_not_of(' ');
          if (i == std::string_view::npos) return 0;

          // sign
          bool flag{ sv[i] == '-' };

          if (sv[i] == '-' || sv[i] == '+') {
               i++;
          }
   
          long num{ 0 };

          while (i < sv.size() && std::isdigit(sv[i]))
          {
               int digit = sv[i++] - '0';

               // Check for overflow 
               if (num > (INT_MAX - digit) / 10) {
                    return flag ? INT_MIN : INT_MAX;
               }

               num = num * 10 + digit;
          }

          return static_cast<int>(flag ? -num : num);
     }
};

