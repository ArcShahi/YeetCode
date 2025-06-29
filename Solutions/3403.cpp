// 3403. Find the Lexicographically Largest String From the Box I
#include <string>
#include <iostream>
// MOST BRAIN DEAD Question

// just create a  substring from every index of size : n-numFriends+1

class Solution {
public:
     std::string answerString(std::string word, int numFriends)
     {
          if (numFriends == 1) return word;

          std::string box{};
          int count=word.length() - numFriends + 1 ;

          for (int i{ 0 }; i < word.size(); ++i)
          {
               int len = std::min(count, static_cast<int>(word.length() - 1));
               box = std::max(box, word.substr(i, len));
          }
          return box;
     }
};
