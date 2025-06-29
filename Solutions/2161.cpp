// 2161. Partition Array According to Given Pivot
#include <vector>

#include <iostream>
class Solution {
public:

     Solution()
     {
          std::ios::sync_with_stdio(false);
          std::cin.tie(nullptr);
     }
public:
     std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {

          std::vector<int> v{};
          v.reserve(nums.size());
          int pcount{ 0 };

          for (const auto& i : nums)
          {
               if (i < pivot)
                    v.push_back(i);

               if (i == pivot) 
                    ++pcount;
          }
          for (int i{ 0 }; i < pcount; ++i) v.push_back(pivot);

          for (const auto& i : nums)
               if (pivot < i) v.push_back(i);

          return v;
         
     }
};
