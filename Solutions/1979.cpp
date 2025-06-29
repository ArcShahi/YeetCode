 // 1979. Find Greatest Common Divisor of Array

#include <numeric>
#include <algorithm>
#include <vector>

class Solution {
public:
     int findGCD(std::vector<int>& nums) {

          auto [min,max] = std::minmax_element(begin(nums), end(nums));

          return std::gcd(*min,*max);

     }
};

