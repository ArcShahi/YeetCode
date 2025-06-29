// 1323. Maximum 69 Number

#include <string>

class Solution {
public:
     int maximum69Number(int num) {
        
          const auto s = [](auto str)
               {
                    if (auto itr = std::find(begin(str), end(str), '6'); itr != end(str))
                         *itr = '9';   
                    return str;
               };
          return std::stoi(s(std::to_string(num)));
        
     }
};