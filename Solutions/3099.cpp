// 3099. Harshad Number

auto digit_sum(int x)
{
     int sum{ 0 };
     while (x){
          sum += x % 10;
          x /= 10;
     }
     return sum;
}

class Solution {
public:
     int sumOfTheDigitsOfHarshadNumber(int x) {
          auto dig_sum{ digit_sum(x) };
          return x % dig_sum == 0 ? dig_sum : -1;
     }
};