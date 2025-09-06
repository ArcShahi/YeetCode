// 347. Top K Frequent Elements

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

// TIME COMPLEXITY : O(N+ULogU)
// SPACE COMPLEXITY : O(U)    
// U is number of unique elements

class Solution {
public:
     std::vector<int> topKFrequent(std::vector<int>& nums, int k) {

          std::unordered_map<int, int> hashmap{};
          for (const auto& i : nums)
               ++hashmap[i];

          std::vector<std::pair<int, int>> vec(begin(hashmap), end(hashmap));

          std::sort(begin(vec), end(vec), [](const auto& x, const auto& y)
               {return y.second < x.second; });

          std::vector<int> top{};
          top.reserve(k);
          for (int i{ 0 }; i < k; ++i)
               top.push_back(vec[i].first);

          return top;

     }
};