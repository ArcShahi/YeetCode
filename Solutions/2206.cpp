// 2206. Divide Array Into Equal Pairs

#include <vector>
#include <algorithm>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
// SPACE COMPPLEXITY : O(N)

class Solution {
public:
     bool divideArray(std::vector<int>& nums) {

          std::unordered_map<int, int> hashmap{};
          for (const auto& i : nums)
               ++hashmap[i];

          return std::ranges::all_of(hashmap, [](const auto& e) { return e.second % 2 == 0; });
     }
};