// 1704. Determine if String Halves Are Alike

#include <string>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

 bool is_vowel(char x)
{
     static const std::string vowels{ "aeiouAEIOU" };
     return vowels.find(x) != std::string::npos;
}

class Solution {
public:
     bool halvesAreAlike(std::string s) {

          const size_t mid{s.length() / 2 };
          int left{ 0 }, right{ 0 };

          for (size_t i{ 0 }; i < s.length(); ++i)
          {
               if (is_vowel(s[i]))
               {
                    if (i <= mid) ++left;
                    else ++right;
               }
          }

          return left == right;
     }
};