// 2325. Decode the Message
#include <unordered_map>
#include <string>
class Solution {
public:
     std::string decodeMessage(std::string key, std::string message) {

          std::unordered_map<char, char> table{};
          table.reserve(27);
          table[' '] = ' '; // space

          for (char c = 'a'; const auto& k : key)
               if (!table.contains(k))
                    table[k] = c++;

          for (auto& c : message)
               c = table[c];

          return message;
     }
};