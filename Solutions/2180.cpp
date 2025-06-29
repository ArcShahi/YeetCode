// 2180. Count Integers With Even Digit Sum


bool is_even_sum(int n)
{
     int sum{ 0 };

     while (n>0)
     {
          sum+=(n % 10);
          n /= 10;
     }

     return !(sum & 1);
}

class Solution {
public:
     int countEven(int num) {

          int count{ 0 };
          for (int i{ 2 }; i <= num; ++i)
          {
               if (is_even_sum(i)) ++count;
          }
          return count;
     }
};