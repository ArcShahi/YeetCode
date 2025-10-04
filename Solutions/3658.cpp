// 3658. GCD of Odd and Even Sums

#include <numeric>

// TIME COMPLEXITY : O(1)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int gcdOfOddEvenSums(int n) {

          return n;

          // Sum of even numbers : n(n+1)
          // sum of odd number : n^2 
          // Gretest number that can divide both : n^2+n and n^2 is n 
     }
};

// TIME COMPLEXITY : O(Log(N^2));
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int gcdOfOddEvenSums(int n) {

          int even{ (n * n) + n };
          int odd = { n * n };
          return std::gcd(even, odd);
     }
};