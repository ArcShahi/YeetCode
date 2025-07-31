// 1492. The kth Factor of n

// TIME COMPLEXITY  : O(N)
// SPACE COMPLEXITY : O(1)

// TODO : Reduce Time complexity

class Solution {
public:
     int kthFactor(int n, int k) {

          if (k < 1 && n < k) return -1;

          for (int i{ 1 }; i <= n; ++i)
          {
               if (n % i == 0) --k;
               if (k == 0) return i;
   
          }
          return -1;
     }
};