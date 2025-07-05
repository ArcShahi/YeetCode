// 1394. Find Lucky Integer in an Array

#include <vector>
#include <unordered_map>

// TIME COMPLEXITY : O(n)
// SPACE : O(n)

class Solution {
public:
     int findLucky(std::vector<int>& arr) {

          std::unordered_map<int, int> hashmap{};
          for (const auto& i : arr)
               ++hashmap[i];

          int max{ -1 };
          for (const auto& [k, v] : hashmap)
               if (k == v) max = std::max(max, k);

          return max;
     }
};
