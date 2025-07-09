// 345. Reverse Vowels of a String

#include <string>
#include <algorithm>


// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY: O(1)
bool is_vowel(char x)
{
     static const std::string vowels{ "aeiouAEIOU" };
     return vowels.find(x) != std::string::npos;
}

class Solution {
public:
     std::string reverseVowels(std::string s) {

          auto l{ begin(s) };
          auto r{ end(s) - 1 };

          while (l<r)
          {
               if (!is_vowel(*l)) ++l;
               if (!is_vowel(*r)) --r;
               if (is_vowel(*l) && is_vowel(*r))
                    std::iter_swap(l++, r--);
          }
          return s;
     }
};