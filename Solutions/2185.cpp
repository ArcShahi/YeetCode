// 2185. Counting Words With a Given Prefix

#include <string>
#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(N*P) , P is max word size
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int prefixCount(std::vector<std::string>& words, std::string pref) {

          return std::ranges::count_if(words, [&](const auto& word)
               {return word.starts_with(pref); });
     }
};