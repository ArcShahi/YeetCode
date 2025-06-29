// 2390. Removing Stars From a String
#include <vector>
#include <string>

// TIME COMPLEXITY :O(n)
class Solution {
public:
     std::string removeStars(std::string s) {
          
          std::string t{};
          t.reserve(s.length());
          for (const auto c : s)
          {
               if (c != '*') t.push_back(c);
               else t.pop_back();
          }
          return t;        
     }
};