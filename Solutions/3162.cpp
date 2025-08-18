// 3162. Find the Number of Good Pairs I

#include <vector>
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {

          int count{};
          for (const auto& i : nums1)
               for (const auto& j : nums2)
                    if (i % (j * k) == 0)++count;

          return count;
     }
};