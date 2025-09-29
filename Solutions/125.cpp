// 125. Valid Palindrome

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPELXITY : O(1)


class Solution {
public:
     bool isPalindrome(std::string& s) {

          auto l{ begin(s) }, r{ end(s) - 1 };

          while (l<r)
          {
               if (!isalnum(*l))
               {
                    ++l;
                    continue;
               }
               if (!isalnum(*r))
               {
                    --r;
                    continue;
               }

               if (tolower(*l) != tolower(*r))
                    return false;

               ++l;
               --r;
          }

          return true;
     }
};
