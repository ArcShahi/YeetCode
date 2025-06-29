// 7. Reverse Integer

#include <print>

class Solution {
public:
     int reverse(int x) {
          int res = 0;

          while (x != 0) 
          {
               int digit = x % 10;
               x /= 10;

               // Overflow check ( Range of int +2,147,483,647 to -2,147,483,648
               if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) return 0;
               if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) return 0;

               // Upadate only if it doesn't overflow or underflow
               res = res * 10 + digit;
          }
          return res;
     }
};


