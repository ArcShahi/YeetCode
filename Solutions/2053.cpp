// 2053. Kth Distinct String in an Array

#include <string>
#include <vector>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)


class Solution {
public:
     std::string kthDistinct(std::vector<std::string>& arr, int k) {
           
          std::unordered_map<std::string, int> htab{};
          for (const auto& str : arr)
               ++htab[str];

          for (const auto& str : arr)
          {
               if (htab[str] == 1) --k;
               if (k == 0) return str;
          }

          return "";
     }
};