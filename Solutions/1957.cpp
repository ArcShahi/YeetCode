// 1957. Delete Characters to Make Fancy String

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::string makeFancyString(std::string s) {

          std::string fancy{};
          for (size_t i{ 0 }; i < s.length(); ++i) {
               if (2 <= i && s[i] == s[i - 1] && s[i] == s[i - 2])
                    continue;
               fancy.push_back(s[i]);
          }
          return fancy;
     }
};

class Solution2 {
public:
     std::string makeFancyString(std::string s) {

          char pvs{ '0' };
          int count{ 0 };

          std::string fancy{};

          for (const auto& i : s)
          {
               if (pvs == i) ++count;
               else count = 1;
               if (count < 3) fancy.push_back(i);
               pvs = i;
          }
          return fancy;
     }
};

