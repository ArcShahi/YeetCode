// 2810. Faulty Keyboard

#include <string>
#include <algorithm>

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(n)

class Solution {
public:
     std::string finalString(std::string s) {

          std::string str{};
          for (const auto c : s)
          {
               if (c == 'i')
                    std::ranges::reverse(str);
               else
                    str.push_back(c);
          }
          return str;
     }
};