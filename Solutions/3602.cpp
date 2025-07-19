// 3602. Hexadecimal and Hexatrigesimal Conversion

#include <string>

// TIME COMPLEXITY : O(logN)
// SPACE COMPLEXITY : O(logN)

std::string to_base(int num, int base) noexcept
{
     static const char* dig{ "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
     std::string str{};
     while (num)
     {
          str.push_back(dig[num % base]);
          num /= base;
     }
     std::reverse(begin(str), end(str));
     return str;
}

class Solution {
public:
     std::string concatHex36(int n) {

          return to_base(n * n, 16) + to_base(n * n * n, 36);
     }
};