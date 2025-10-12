// 2109. Adding Spaces to a String

#include <string>
#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N+M)


class Solution {
public:
     std::string addSpaces(std::string s, std::vector<int>& spaces) {

          std::string str{};
          str.reserve(s.length() + spaces.size());
          auto it{ begin(spaces) };

          for (size_t i{ 0 }; i < s.size(); ++i)
          {
               if (it != end(spaces) && *it == i)
               {
                    str.push_back(' ');
                    ++it;
               }
               str.push_back(s[i]);
          }

          return str;
     }
};