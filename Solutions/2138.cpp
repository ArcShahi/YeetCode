// 2138. Divide a String Into Groups of Size k
#include <string>
#include <vector>

class Solution {
public:
     std::vector<std::string> divideString(std::string s, int k, char fill) {

          std::vector<std::string> div{};
          div.reserve(s.size() / k);

          if (const int rem = s.length() % k; rem != 0)
               s.append(k - rem, fill);

          for (int i{ 0 }; i < s.length(); i += k)
               div.push_back(s.substr(i, k));
          
          return div;
     }
};