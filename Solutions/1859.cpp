// 1859. Sorting the Sentence

#include <string>
#include <vector>
#include <sstream>

// TIME COMPLIXTY : O(N)
// SPACE COMPLEIXITY : O(1) AUXILIARY

class Solution {
public:
     std::string sortSentence(std::string s) {

          std::vector<std::string> words(9);
          std::string temp{};
          for (const auto& i : s)
          {
               if (i == ' ') continue;
               if (std::isalpha(i)) temp.push_back(i);
               else if (std::isdigit(i))
               {
                    int idx{ i - '0' };
                    words[idx - 1] = std::move(temp);
               }
          }

          std::string sentence{};
          for (auto& i : words)
               if (!i.empty())
                    sentence += i + ' ';

          sentence.pop_back();
          return sentence;
     }
};


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution2 {
public:
     std::string sortSentence(std::string s) {

          std::vector<std::string> words(9);
          std::istringstream iss(s);

          std::string temp{};
          while (iss >> temp)
          {
               int idx{ temp.back() - '0' };
               temp.pop_back();
               words[idx-1] = temp;
          }

          std::string sentence{};
          for (auto& i : words)
               if (!i.empty())
                    sentence += i + ' ';

          sentence.pop_back();        
          return sentence;
     }
};