// 2255. Count Prefixes of a Given String

#include <vector>
#include <string>
#include <algorithm>

// TIME CMPLEXITY : O(N*P) ; p is the max size of prefix
// SPACE COMPLEXIY : O(1)

class Solution {
public:
     int countPrefixes(std::vector<std::string>& words, std::string s) {

          return std::ranges::count_if(words, [&](const auto& prefix) {
               return s.starts_with(prefix);
               });
     }
};