// 575. Distribute Candies

#include <vector>
#include <unordered_set>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(1)

class Solution {
public:
     int distributeCandies(std::vector<int>& candyType) {

          std::unordered_set set(begin(candyType), end(candyType));
          return std::min(set.size(), candyType.size());
     }
};
