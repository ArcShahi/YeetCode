// 2283. Check if Number Has Equal Digit Count and Digit Value
#include <string>
#include <unordered_map>

class Solution {
public:
     bool digitCount(std::string num) {
          std::unordered_map<char, int> hashmap{};

          for (const auto& c : num)
               ++hashmap[c];

          for (int i{ 0 }; i < num.length(); ++i) {
               char digit = i +'0';
               int expected = num[i] - '0';
               int actual = hashmap.count(digit) ? hashmap[digit] : 0;

               if (actual != num[i] - '0')
                    return false;
          }
          return true;
     }
};

