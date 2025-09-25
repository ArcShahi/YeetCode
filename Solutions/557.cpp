// 557. Reverse Words in a String III

#include <string>
#include <algorithm>
#include <sstream>

// TIME COMPLEXITY : O(N)
// SPACE COMPELXITY: 0(N)

class Solution {
public:
     std::string reverseWords(std::string s) {

          std::ostringstream oss{};
          std::string word{};

          for (const auto& c : s)
          {
               if (!isspace(c)) word.push_back(c);
               else
               {
                    std::ranges::reverse(word);
                    oss << word << ' ';
                    word.clear();
               }
          }
          std::ranges::reverse(word);
          oss << word;

          return oss.str();
     }
};