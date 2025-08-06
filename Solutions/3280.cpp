// 3280. Convert Date to Binary

#include <sstream>
#include <string>
#include <algorithm>

std::string to_binary(int n)
{
     if (n == 0) return "";

     std::string bin{};

     while (n>0)
     {
          bin.push_back(n%2+'0');
          n >>= 1; // right shift 1
     }
     std::ranges::reverse(bin);
     return bin;
}

class Solution {
public:
     std::string convertDateToBinary(std::string date) {

          int yyyy = std::stoi(date.substr(0, 4));
          int mm = std::stoi(date.substr(5, 2));
          int dd = std::stoi(date.substr(8, 2));

          return to_binary(yyyy) + '-' + to_binary(mm) + '-' + to_binary(dd);
    
     }
};
