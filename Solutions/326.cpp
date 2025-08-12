// 326. Power of Three

#include <cmath>

// TIME COMPLEXITY : O(1)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     bool isPowerOfThree(int n) {
          return n > 0 && 1162261467 % n == 0;
     }
};

/*

Explanation

 The constraint it signed integer so : INT_MAX 2147483647 

  Let's find the largest valid power ( befor it overflows )

  k<=log(INT_MAX)/log(3) = 19 ( truncating floating parts)

  3^k= 3^19 = 1162261467

  So if a number divides it completely  Then n is a divisor of 3^19, meaning it’s a power of 3
  (since 3 is prime — its only divisors are its powers).

*/