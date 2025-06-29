// 1221. Split a String in Balanced Strings

#include <string>
class Solution {
public:
     int balancedStringSplit(std::string s) {

          int n{};
          int count{ 0 };

          for (const auto c : s)
          {
               if (c == 'R')++count;
               else --count;

               if (count == 0) ++n;
          }
          return n;
     }
};

// whenever the count will reach 0 means it's balanced and we can split it