// 819. Most Common Word

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>


// TIME COMPLEXITY : O(N+M)
// SPACE COMPLEXITY : O(N+M)


class Solution {
public:
     std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {

          // replace evey non-alpanumeric char with space
          std::ranges::for_each(paragraph, [](auto& c)
               {
                    if (!isalnum(c)) c = ' ';
                    else c = tolower(c);
               });


          std::unordered_set ban(begin(banned), end(banned));
          std::unordered_map<std::string, int> hmap{};

          std::istringstream iss(paragraph);
          std::string word{};

          while (iss>>word)
               if (!ban.contains(word)) ++hmap[word];


          auto it{ std::ranges::max_element(hmap,[](const auto& a, const auto& b)
                                            {return a.second < b.second; }) };

          return it->first;
     }
};