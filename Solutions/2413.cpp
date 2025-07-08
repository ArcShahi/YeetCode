// 2413. Smallest Even Multiple

#include <numeric> // for std::lcm

class Solution {
public:
     int smallestEvenMultiple(int n) {

          return std::lcm(2, n);
          
          // ANOTHER : return (n % 2 == 0) ? n : n * 2;
     }
};


