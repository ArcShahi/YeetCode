// 709. To Lower Case

#include <string>
#include <algorithm>


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)


class Solution {
public:
     std::string toLowerCase(std::string s) {

          std::for_each(begin(s), end(s), [](auto& c) {c = std::tolower(c); });
          return s;
     }
};