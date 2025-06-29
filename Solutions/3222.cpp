// 3222. Find the Winning Player in Coin Game
#include <string>


class Solution {
public:
     std::string winningPlayer(int x, int y) {
          // Alice plays first
          int turn{ 0 };

          // We NEED 1 '75' coins and 4 '10' coins 
          while (x>=1 && y>=4)
          {
               --x; 
               y -= 4;
               ++turn;
          }

          return (turn & 1) ?  "Alice" : "Bob";
     }
};

// Better

// Similar to ballon question 1189. Maximum Number of Balloons
std::string winningPlayer(int x, int y) {
    
  // We need atleast 1 '75' coin and 4 '10' coins
     int turn{ std::min(x,y / 4) }; // max number of move possible
     return (turn & 1) ? "Alice" : "Bob"; // if odd Alice ends with last move ....
}