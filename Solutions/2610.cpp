// 2610. Convert an Array Into a 2D Array With Conditions

#include <vector>
#include <unordered_map>

// TIME COMPLEXITY  : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {

          std::unordered_map<int, int> hashmap{};
          for (const auto& i : nums)
               ++hashmap[i];

          int max_freq{ 0 };
          for (const auto& e : hashmap)
               max_freq = std::max(max_freq, e.second);

          std::vector<std::vector<int>> matrix(max_freq);

          for (const auto& [num, count] : hashmap)
               for (int i{ 0 }; i < count; ++i)
                    matrix[i].push_back(num);

          return matrix;
     }
};
