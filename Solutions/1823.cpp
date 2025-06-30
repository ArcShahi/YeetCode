// 1823. Find the Winner of the Circular Game

class Solution {
public:
     int findTheWinner(int n, int k) {
          int player{ 0 };
          for (int i{ 2 }; i <= n; ++i) {
               player = (player + k) % i;
          }
          return player + 1;
     }
};