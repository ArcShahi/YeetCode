// 2894. Divisible and Non-divisible Sums Difference

class Solution {
public:
     int differenceOfSums(int n, int m) {

          
          int gauss_sum{ n * (n + 1) / 2 };

          // Multiple of m in range [1,n]
          int k{ n / m };

          // Sum of multiples of m : m,2m+3m+...km

          int n2 = m * k * (k + 1) / 2;

          // sum of non-multiples
          int n1 = gauss_sum - n2;



          return n1 - n2;
     }
};

class Solution2 {
public:
     int differenceOfSums(int n, int m) {
          
          int n1{ 0 };
          int n2{};

          for (int i{ 1 }; i <= n; ++i)
          {
               if (i % m != 0) n1 += i;
               else n2 += i;
          }

          return n1 - n2;
     }
};