// 3289. The Two Sneaky Numbers of Digitville

#include <vector>
#include <unordered_map>

// TIME COMPLEXITY :O(N)
// SPACE COMPLEXITY:O(N)

class Solution {
public:
     std::vector<int> getSneakyNumbers(std::vector<int>& nums) {

          std::vector<int> sneaky{};
          std::unordered_map<int, int> hashmap{};
          for (const auto& i : nums)
          {
               if (!hashmap.count(i))
                    ++hashmap[i];
               else
                    sneaky.push_back(i);
          }
          return sneaky;
     }
};

