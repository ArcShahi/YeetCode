// 657. Robot Return to Origin

#include <string>


// TIME COMPLEXITY : O(N)
// SPACE COMPLEITY : O(1)
class Solution {
public:
     bool judgeCircle(std::string moves) {
        
          int x{ 0 }, y{ 0 }; // origin

          for (const auto cmd : moves)
          {
               switch (cmd)
               {
               case 'U':++y; break;
               case 'D':--y; break;
               case 'L':--x; break;
               case 'R':++x; break;
               default:
                    break;
               }
          }
          return (x == 0 && y == 0);
     }
};