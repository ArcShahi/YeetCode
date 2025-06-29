// 1071. Greatest Common Divisor of Strings 

#include <string>
#include <numeric>

// TIME COMPLEXITY : O(M+N)
// SPACE COMPLEIXTY : O(M+N)

class Solution {
public:
     std::string gcdOfStrings(std::string str1, std::string str2) {

          if (str1 + str2 != str2 + str1) return "";

          return str1.substr(0, std::gcd(str1.length(), str2.length()));
     }
};