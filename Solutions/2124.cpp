// 2124. Check if All A's Appears Before All B's

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPELXITY : O(1)

class Solution {
public:
     bool checkString(std::string s) {

          bool seen{ false }; // seen b
          for (const auto& c : s)
          {
               if (c == 'a' && seen) return false;
               else if (c == 'b') seen = true;
          }
          return true;
     }
};