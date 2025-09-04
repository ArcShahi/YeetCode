// 2404. Most Frequent Even Element

#include <vector>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     int mostFrequentEven(std::vector<int>& nums) {

          std::unordered_map<int, int> emap{};
          int m{ -1 }, c{ 0 };

          for (const auto& num : nums)
          {
               if (num % 2 == 0)
               {
                    int count{ ++emap[num] };

                    if (c < count || (c == count) && num < m)
                    {
                         c = count;
                         m = num;
                    }
               }
          }
          return m;
     }
};
