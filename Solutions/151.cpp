// 151. Reverse Words in a String

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)


class Solution {
public:
     std::string reverseWords(std::string s) {

          std::istringstream iss(s);
          std::vector<std::string> tokens{};
          
          std::string buffer{};
          while (iss >> buffer)
               tokens.push_back(buffer);
          
          std::reverse(begin(tokens), end(tokens));
        
          buffer.clear();
          for (auto& words : tokens)
               buffer += words + ' ';

          buffer.pop_back();
          return buffer;
     }
};