// 2200. Find All K-Distant Indices in an Array

#include <vector>

class Solution {
public:
     std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {

          int n = nums.size();
          std::vector<int> key_idx{};
          for (int i{ 0 }; i < n; ++i)
               if (nums[i] == key)
                    key_idx.push_back(i);

          std::vector<int> idx{};
          idx.reserve(n);

          for (int i{ 0 }; i < n; ++i)
          {
               for (const auto& j : key_idx)
               {
                    if (std::abs(i - j) <= k) {
                         idx.push_back(i);
                         break;
                    }
               }
          }
          return idx;

     }
};