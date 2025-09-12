// 3227. Vowels Game in a String

#include <string>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXIY : O(1)

class Solution {
public:
     bool doesAliceWin(std::string s) {
          
          auto is_vowel = [](const char c) {static const std::string vowels{ "aeiou" };
          return vowels.find(c) != std::string::npos;
               };
          // She only loses if vowels count is 0.
          return std::ranges::any_of(s, is_vowel);
     }
};