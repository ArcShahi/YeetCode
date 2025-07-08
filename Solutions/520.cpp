// 520. Detect Capital

#include <string>

class Solution {
public:
     bool detectCapitalUse(std::string word) 
     {
          int cap{ 0 };
          int N = word.size();

          for (auto c : word)
               if (isupper(c))
                    ++cap;

          int lower{N - cap };

          if (cap == N || lower == N || (isupper(word[0]) && cap == 1))
          {
               return true;
          }
          return false;
     }
};
