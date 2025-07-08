// 168. Excel Sheet Column Title

#include <string>
#include <algorithm>

class Solution {
public:
     std::string convertToTitle(int col) {
          std::string title;

          while (col--> 0) {
               char c = (col % 26) + 'A'; // get the char
               title.push_back(c);
               col /= 26;
          }

          std::ranges::reverse(title);
          return title;
     }
};

