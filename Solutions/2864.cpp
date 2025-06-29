// 2864. Maximum Odd Binary Number

#include <string>
#include <algorithm>


class Solution {
public:
     std::string maximumOddBinaryNumber(std::string s) {

          auto bit{ std::ranges::count(s,'1') };
          std::ranges::fill(s, '0');
          std::replace(begin(s), begin(s) + bit - 1, '0', '1');
          s.back() = '1';
          return s;
         
     }
};