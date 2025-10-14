// 2828. Check if a String Is an Acronym of Words

#include <string>
#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)


class Solution {
public:
     bool isAcronym(std::vector<std::string>& words, std::string s) {

          std::string acro{};
          for (const auto& word : words)
               acro.push_back(word[0]);

          return acro == s;
     }
};