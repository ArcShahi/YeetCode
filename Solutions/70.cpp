// 70. Climbing Stairs


class Solution {
public:
     int climbStairs(int n) {
          if (n <= 2) return n;

          int f = 1, s = 2;

          // It's just Fibonacci Number till n
          for (int i{ 3 }; i <= n; ++i) {
               int next = f + s;
               f = s;
               s = next;
          }

          return s;
     }
};