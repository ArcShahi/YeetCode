// 3005. Count Elements With Maximum Frequency

#include <vector>
#include <algorithm>


// TIME COMPLEXITY : O(N)
// SPACE COMPLEIXTY : O(N)

class Solution {
public:
     int maxFrequencyElements(std::vector<int>& nums) {

          std::vector<int> v(100);
          for (const auto& i : nums) ++v[i];
          auto maxf{*std::ranges::max_element(v) };
          return maxf * std::ranges::count_if(v, [&](int x) {return x == maxf; });
     }  
};