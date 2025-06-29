
// 2016. Maximum Difference Between Increasing Elements
#include <vector>
class Solution {
public:
     int maximumDifference(std::vector<int>& nums) {


          // INF
          int smallest = std::numeric_limits<int>::max();
          int diff{ 0 };

          for (const auto& i : nums)
          {
               smallest = std::min(i,smallest);
               diff = std::max(diff, i - smallest);
          }
          return diff;
     }
};