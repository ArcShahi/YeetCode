// 2798. Number of Employees Who Met the Target

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target) {

          return std::count_if(begin(hours), end(hours), [&target](const int x)
               {return x >= target; });
     }
};