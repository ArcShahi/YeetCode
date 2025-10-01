// 3174. Clear Digits

#include <string>

// TIME COMPLEXITY : O(N)
// SPAC COMPLEXITY : O(N)

class Solution {
public:
     std::string clearDigits(std::string s) {

          std::string out{};
          for (char c : s)
          {
               if (isdigit(c) && !out.empty()) out.pop_back();
               else out.push_back(c);
          }
          return out;
     }
};