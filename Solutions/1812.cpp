// 1812. Determine Color of a Chessboard Square
#include <string>

class Solution {
public:
     bool squareIsWhite(std::string coordinates) {

          int x{ coordinates[0] - 'a' + 1 };
          int y{ coordinates[1] - '0' };
          return (x + y) & 1;
     
     }
};