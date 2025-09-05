// 1636. Sort Array by Increasing Frequency

#include <vector>
#include <unordered_map>
#include <algorithm>

// TIME COMPLEXITY : O(nLogn)
// SPACE COMPLEXITY: O(1)

class Solution {

public:
     std::vector<int> frequencySort(std::vector<int>& nums) {
       
          std::vector<int> freq(201);
          for (const auto& num : nums)
               ++freq[num + 100]; // Account for negative nums


          auto cmp = [&](const auto a, const auto b)
               {
                    const int x{ freq[a + 100] }, y{ freq[b + 100] };
                    if (x == y) return b < a;
                    return x < y;
               };

          std::ranges::sort(nums, cmp);
          return nums;
     }
};