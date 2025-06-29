// 1025. Divisor Game


// whoever starts with an even n can always win
class Solution {
public:
     bool divisorGame(int n) {
          return n % 2 == 0;
     }
};