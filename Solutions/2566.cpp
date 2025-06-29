// 2566. Maximum Difference by Remapping a Digit

#include <algorithm>
#include <string>

class Solution {
public:
     int minMaxDifference(int num) {
          auto s = std::to_string(num);
          auto t{ s };
          
          char x{ *std::ranges::find_if(s,[](char c) {return c != '9'; }) };
          char y{ t.front() };

          for (int i{ 0 }; i < s.length(); ++i)
          {
               if (s[i] == x) s[i] = '9';
               if (s[i] == y) t[i] = '0';
          }
          return std::stoi(s) - std::stoi(t);
       
     }
};
