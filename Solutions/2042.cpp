
// 2042. Check if Numbers Are Ascending in a Sentence
#include <sstream>
#include <string>

class Solution {
public:
     bool areNumbersAscending(std::string s) {

          std::istringstream ins{ s };

          int num{ -1 };
          std::string word{};

          while (ins>>word)
          {
               int temp{-1};
               if (isdigit(word[0]))
               {
                    temp = std::stoi(word);

                    if (num < temp)
                         num = temp;
                    else
                         return false;
               }         
              
          }
          return true;
     }
};

