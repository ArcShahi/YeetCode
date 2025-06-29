// 2535. Difference Between Element Sum and Digit Sum of an Array

#include <vector>

int digit_sum(int x)
{
     if (x < 10) return x;

     int sum{ 0 };

     while (x>0)
     {
          sum += x % 10;
          x /= 10;
     }
     return sum;
}


class Solution {
public:
     int differenceOfSum(std::vector<int>& nums) {

          int x{0};
          int y{ 0 };

          for (const auto& i : nums)
          {
               x += i;
               y += digit_sum(i);
          }

          return std::abs(x-y);
     }
};