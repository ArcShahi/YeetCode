

// 191. Number of 1 Bits

#include <iostream>

class Solution {
public:
     int hammingWeight(uint32_t n) {

          int count{ 0 };

          while (n)
          {
               // removes the last '1' bit from n
               n = n & (n - 1);
               ++count;
          }

          return count;
     }
};


/*
 
Performs & with x-1 every time . 
It basically performs pop_back() only if last bit is 1 no wasting time on bit that are 0.

*/