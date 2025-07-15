// 3136. Valid Word

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(1)

class Solution {
public:
     bool isValid(std::string word) {

          if (word.length() < 3) return false;

          auto is_vowel = [](char x) {static const std::string vowels{ "aeiouAEIOU" };
          return vowels.find(x) != std::string::npos; };

          bool vflag{ false };
          bool cflag{ false };
          for (const auto& c : word)
          {
               if (!std::isalnum(c)) return false;
               else if (is_vowel(c)) vflag= true;
               else if (std::isalpha(c) && !is_vowel(c)) cflag = true;
          }
          return (vflag && cflag);
     }
};