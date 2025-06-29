// 1929. Concatenation of Array

#include <vector>
// TIME COMPLEXITY :O(n)
// SPACE COMPLEXITY :O(n)

class Solution {
public:
     std::vector<int> getConcatenation(std::vector<int>& nums) {

          std::vector<int> concat{};
          concat.reserve(nums.size() * 2);
          concat.insert(end(concat), begin(nums), end(nums));
          concat.insert(end(concat), begin(nums), end(nums));
          return concat;

     }
};