// 4. Median of Two Sorted Arrays
#include <vector>
#include <algorithm>
#include <iterator>


class Solution {
public:
     double findMedianSortedArrays(std::vector<int>& a, std::vector<int>& b) {

          std::vector<int> merged{};
          std::ranges::merge(a, b, std::back_inserter(merged));
          int n = merged.size();

          // Maths Formula
          if (n & 1)
          {
               return merged[n / 2];
          }
          else
          {
               return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
          }
     }
};