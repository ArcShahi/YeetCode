// 2652. Sum Multiples


// TIME COMPLEXITY : O(1)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int sumOfMultiples(int n) {
        
          // N( a U b U C ) = N(a) + N(b)  + N(c) - N( a n b ) - N( b n c)  + N( a n b n c )

          return sum(n, 3) + sum(n, 5) + sum(n, 7) - sum(n, 15) - sum(n, 21) 
               - sum(n, 35) + sum(n, 105);
     }
     int sum(int n, int k)
     {
          int t{ n / k }; // Number of multiples in range [1,n]
          return k * t * (t + 1) / 2; // sum of multiples
     }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int sumOfMultiples(int n) {
          int sum{ 0 };

          for (int x{ 1 }; x <= n; ++x)
               if (x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
                    sum += x;
          
          return sum;
     }
};