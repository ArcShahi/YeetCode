// 125. Valid Palindrome

#include <string>

class Solution {
public:
     bool isPalindrome(std::string& s) {
          
          auto l{ s.begin() };
          auto r{ s.end() - 1 };

          while (l<r)
          {
               if (not isalnum(*l))
               {
                    ++l;
                    continue;
               }
               if (not isalnum(*r))
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
