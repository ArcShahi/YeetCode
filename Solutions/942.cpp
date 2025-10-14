// 942. DI String Match

#include <vector>
#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::vector<int> diStringMatch(std::string s) {

          const auto sz{ s.length() };
          std::vector<int> vec{};
          vec.reserve(sz);

          int i = 0, h = sz;

          for (const auto c : s)
          {
               if (c == 'I')vec.push_back(i++);
               else vec.push_back(h--);
          }

          vec.push_back(i);
          return vec;
     }
};