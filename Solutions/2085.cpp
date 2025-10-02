// 2085. Count Common Words With One Occurrence

#include <vector>
#include <string>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)


class Solution {
public:
     int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2) {

          std::unordered_map<std::string, int> map1{};
          for (const auto& word : words1)
               ++map1[word];

          std::unordered_map<std::string, int> map2{};
          for (const auto& word : words2)
               if (map1.contains(word)) ++map2[word];

          int count{ 0 };
          for (const auto& [key, val] : map2)
               if (val == 1 && map1[key] == 1) ++count;

          return count;
     }
};

