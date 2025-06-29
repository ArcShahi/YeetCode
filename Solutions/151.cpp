// 151. Reverse Words in a String

#include <string>
#include <sstream>


class Solution {
public:
     std::string reverseWords(std::string s) {

          std::istringstream iss(s);
          std::string reverse{};
          std::string buffer{};
          while (std::getline(iss,buffer,' '))
          {

          }
     }
};