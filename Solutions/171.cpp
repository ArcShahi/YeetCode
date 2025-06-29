// 171. Excel Sheet Column Number
#include <string>

class Solution {
public:
     int titleToNumber(std::string columnTitle) 
     {
          int title{0};
          for (const char c : columnTitle)
               title = title * 26 + (c - 'A' + 1);

          return title;

     }
};