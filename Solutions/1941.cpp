// 1941. Check if All Characters Have Equal Number of Occurrences

#include <string>
#include <unordered_map>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)


class Solution {
public:
     bool areOccurrencesEqual(std::string s) {

          std::unordered_map<int, int> hmap{};
          for (const auto c : s)
               ++hmap[c];

          auto freq{ begin(hmap)->second };
          return std::ranges::all_of(hmap, [&](auto& e) {return e.second == freq; });
     }
};