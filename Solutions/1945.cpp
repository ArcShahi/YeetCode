// 1945. Sum of Digits of String After Convert
#include <string>

int transform_it(int n)
{
     int sum = 0;
     while (n > 0) {
          sum += n % 10;
          n /= 10;
     }
     return sum;
}

class Solution {
public:
     int getLucky(std::string s, int k)
     {
          std::string digits{};

          // C O N V E R T
          for (char c : s)
          {
               int pos = (c - 'a') + 1;
               digits += std::to_string(pos);
          }

          // FIRST TRANFORMATION
          int sum = 0;
          for (char d : digits)
               sum += d - '0';


          while (--k > 0) sum = transform_it(sum);

          return sum;
     }
};