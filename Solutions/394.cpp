// 394. Decode String

#include <string>
#include <vector>

// OVELOAD operator* for ease

std::string operator*(const std::string& str, int times) {
     std::string result{};
     result.reserve(str.size() * times);
     while (times--> 0) result += str;
     return result;
}


class Solution {
public:
     std::string decodeString(std::string s) {

          std::vector<std::pair<int, std::string>> stk{};
          int num{0};
          std::string str{};
          for (const auto& i : s)
          {
               if (isdigit(i)) num = num * 10 + (i - '0');
               else if (isalpha(i)) str.push_back(i);
               else if (i == '[')
               {
                    stk.push_back({ num,str });
                    num = 0;
                    str = ""; // reset
               }
               else if (i == ']')
               {
                    auto [times, pvs] = stk.back();
                    stk.pop_back();
                    str = pvs + str * times;// overloaded operator*
               }
          }
          return str;
     }
};

