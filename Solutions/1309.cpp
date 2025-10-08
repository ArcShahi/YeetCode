// 1309. Decrypt String from Alphabet to Integer Mapping

#include <string>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)


class Solution {
public:
    std::string freqAlphabets(std::string s) {
          
         const auto n{ s.length() };
         std::string str{};
          char c;

          for (int i = n - 1; i >= 0; i--) 
          {
               if (s[i] == '#')
               {
                    c = 'a' + ((s[i - 2] - '0') * 10) + (s[i - 1] - '0') - 1;
                    str.push_back(c);
                    i -= 2;
               }
               else 
               {
                    c = 'a' + s[i] - '0' - 1;
                    str.push_back(c);
               }
          }
          std::ranges::reverse(str);
          return str;
     }
};