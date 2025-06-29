// 2114. Maximum Number of Words Found in Sentences


#include <string>
#include <sstream>
#include <vector>

class Solution {
public:
     int mostWordsFound(std::vector<std::string>& sentences) {

          int word{ 0 };
         
          for (const auto& str : sentences)
          {
               std::string temp{};
               std::istringstream iss{str}; //o r we could just count spaces...(means words in this case)
               int count{ 0 }; 
               while (iss>>temp)
               {
                    ++count;
               }

               word = std::max(word, count);
               
          }
          return word;
     }
};


class Solution2 {
public:
     int mostWordsFound(std::vector<std::string>& sentences) {

          int count{ 0 };

          for (const auto& words : sentences)
          {
               // If were here means we already have a word and space means next word is coming
               int temp{1}; 
               for (const auto c : words)
                    if (isspace(c)) ++temp;
             
               count = std::max(temp, count);

          }
          return count;
     }
};