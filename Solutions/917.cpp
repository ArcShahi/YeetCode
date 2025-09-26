// 917. Reverse Only Letters

#include <string>
#include <algorithm>
#include <iterator>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// 2 POINTERS

class Solution {
public:
     std::string reverseOnlyLetters(std::string s) {

          auto l{ begin(s) };
          auto r{ end(s) - 1 };

          while (l < r) 
          {
               if (!isalpha(*l)) { ++l; continue; }
               if (!isalpha(*r)) { --r; continue; }
               std::iter_swap(l++, r--);
          }
          return s;
     }
};


namespace rng = std::ranges;

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)

class Solution {

public:
     std::string reverseOnlyLetters(std::string s) {

          std::string str{};
   
          rng::copy_if(s, std::back_inserter(str), [](const auto x) {return isalpha(x); });
          rng::reverse(str);
                
          for (auto it{ begin(str) };auto& c : s)
               if (isalpha(c))
                    c = *it++;

          return s;
     }
};