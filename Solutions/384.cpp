// 384. Shuffle an Array

#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class Solution {
public:
     Solution(std::vector<int>& nums)
          : og{ std::move(nums) },
          engine{ static_cast<std::mt19937::result_type>(std::time(nullptr)) }
     {
     }

     std::vector<int> reset() {
          return og;
     }

     std::vector<int> shuffle() {
          auto shuffled{ og };
          std::shuffle(shuffled.begin(), shuffled.end(), engine);
          return shuffled;
     }

private:
     std::vector<int> og{};
     std::mt19937 engine{};
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */