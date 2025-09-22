// 434. Number of Segments in a String

#include <string>
#include <algorithm>
#include <sstream>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)

class Solution {
public:
     int countSegments(std::string s) {
          if (s.empty()) return 0;

          std::istringstream iss(s);
          std::string words{};
          int count{ 0 };
          while (iss >> words) ++count;
          return count;
     }
};