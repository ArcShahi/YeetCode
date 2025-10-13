// 1619. Mean of Array After Removing Some Elements

#include <vector>
#include <algorithm>
#include <numeric>

// TIME COMPLEXITY : O(NlogN)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     double trimMean(std::vector<int>& arr) {

          std::ranges::sort(arr);
          const auto trim{ static_cast<int>(arr.size() * 0.05)};        
          const auto sum{ std::accumulate(begin(arr) + trim, end(arr) - trim, 0.0) };
          return sum / (arr.size() - 2 * trim);
     }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// REFERECE ; https://leetcode.com/u/votrubac/


class Solution {
public:
     double trimMean(std::vector<int>& arr) {

          const auto sz{ arr.size() }, skip{ sz / 20 };
          std::nth_element(begin(arr), begin(arr) + skip, end(arr));
          std::nth_element(begin(arr) + skip, begin(arr) + sz - skip, end(arr));

          return std::accumulate(begin(arr) + skip, begin(arr) + sz - skip, 0.0)
               / (sz - 2 * skip);
     }
};

