// 1816. Truncate Sentence

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::string truncateSentence(std::string s, int k) {
          
          for (size_t i = 0; i < s.length(); ++i)
               if (std::isspace(s[i]) && --k == 0)
                    return s.substr(0, i);
          
          return s;
     }
};