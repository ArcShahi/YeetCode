// 1844. Replace All Digits with Characters

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)


class Solution {
public:
     std::string replaceDigits(std::string s) {

          for (size_t i{ 1 }; i < s.length(); i += 2)
               s[i] = s[i - 1] + (s[i] - '0');

          return s;
     }
};