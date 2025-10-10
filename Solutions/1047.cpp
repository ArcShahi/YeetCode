// 1047. Remove All Adjacent Duplicates In String

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPELXITY :O(1) ; Ignoring return value

class Solution {
public:
     std::string removeDuplicates(std::string s) {

          std::string out{};

          for (const auto c : s)
          {
               if (!out.empty() && out.back() == c)
                    out.pop_back();
               else 
                    out.push_back(c);
          }
          return out;
     }
};