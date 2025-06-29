// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

#include <string>
#include <algorithm>

class Solution {
public:
     int minPartitions(std::string n) {
          return *std::ranges::max_element(n) - '0';
     }
};
