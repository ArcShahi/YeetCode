// 806. Number of Lines To Write String


#include <vector>
#include <string>


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     std::vector<int> numberOfLines(std::vector<int>& widths, std::string s) {

          const int LIMIT{ 100 };
          int lines{ 1 };
          int pixel{ 0 };

          for (const auto c : s)
          {
               int w{ widths[c - 'a'] };
               pixel += w;

               if (LIMIT < pixel)
               {
                    ++lines;
                    pixel = w;
               }
          }

          return { lines,pixel };
     }
};