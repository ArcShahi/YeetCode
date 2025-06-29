// 9. Palindrome Number

class Solution {
public:
     bool isPalindrome(int x) {

          if (x < 0)
               return false;

          long long rem{ 0 };

          int temp = x;

          while (temp > 0)
          {
               rem *= 10;
               rem += temp % 10;
               temp /= 10;
          }
          return rem == x;

     }
};