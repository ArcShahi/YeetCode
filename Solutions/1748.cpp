// 1748. Sum of Unique Elements

#include <vector>
#include <numeric>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     int sumOfUnique(std::vector<int>& nums) {

          std::unordered_map<int, int> hmap{};
          for (const auto& i : nums)
               ++hmap[i];

          int sum{ 0 };
          for (const auto& [key, val] : hmap)
               if (val == 1) sum += key;

          return sum;

     }
};