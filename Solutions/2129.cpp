// 2129. Capitalize the Title

#include <string>
#include <sstream>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

void capatalize(std::string& str)
{
     std::for_each(begin(str), end(str), [](char& x) {x = std::tolower(x); });
     if (str.length() > 2) str[0] = std::toupper(str[0]);
}

class Solution {
public:
     std::string capitalizeTitle(std::string title) {

          std::istringstream iss(title);
          std::string buffer{};
          std::string str{};

          while (iss>>buffer)
          {
               capatalize(buffer);
               str += buffer + ' ';
          }
          str.pop_back();
          return str;
     }
};