// 3498. Reverse Degree of a String

#include <string>
class Solution {
public:
     int reverseDegree(std::string s) {

          int degree{ 0 };
          for (int i{ 0 }; i < s.length(); ++i)
               degree = degree + ('z' - s[i]+ 1) * (i+1);
          
          return degree;
     }
};
