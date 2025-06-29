// 2652. Sum Multiples

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