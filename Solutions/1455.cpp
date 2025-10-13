// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

#include <string>
#include <sstream>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)


class Solution {
public:
     int isPrefixOfWord(std::string sentence, std::string searchWord) {

          std::istringstream iss(sentence);
          std::string word{};
          int i{ 1 };

          while (iss>>word)
          {
               if (word.starts_with(searchWord)) return i;
               ++i;
          }
          return -1;
     }
};