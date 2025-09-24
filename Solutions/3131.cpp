// 3131. Find the Integer Added to Array I

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int addedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {

          int min1{ 1111 },  min2{ 1111 }; // works as init max cuz i<=nums1[i]<=1000

          for (size_t i{ 0 }; i < nums1.size(); ++i)
          {
               min1 = std::min(min1, nums1[i]);
               min2 = std::min(min2, nums2[i]);
          }
          return min2 - min1;
     }
};