// 455. Assign Cookies

#include <vector>
#include <algorithm>

// SIMILAR TO 2410

// TIME COMPLEXITY : O(Nlogn)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int findContentChildren(std::vector<int>& g, std::vector<int>& s) {

          std::sort(begin(g), end(g));
          std::sort(begin(s), end(s));

          auto i{ begin(g) };
          auto j{ begin(s) };

          int count{ 0 };
          while (i!=end(g) && j!=end(s))
          {
               if (*i <= *j)
               {
                    ++i; ++j;
                    ++count;
               }
               else
                    ++j;
          }
          return count;
     }
};