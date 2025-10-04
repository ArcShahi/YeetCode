// 3683. Earliest Time to Finish One Task

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int earliestTime(std::vector<std::vector<int>>& tasks) {

          int min{1111}; // initial min cuz 1<=s,t<=100

          for (const auto& i : tasks)
               min = std::min(min, i[0] + i[1]);

          return min;
     }
};