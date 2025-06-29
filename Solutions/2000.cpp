// 2000. Reverse Prefix of Word
#include <string>
#include <algorithm>

class Solution {
public:
     std::string reversePrefix(std::string word, char ch) 
     {
          auto itr = std::find(begin(word), end(word), ch);
          if (itr == end(word)) return word;

          std::reverse(begin(word), itr+1);
          return word;
     }
};