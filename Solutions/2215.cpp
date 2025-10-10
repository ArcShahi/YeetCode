// 2215. Find the Difference of Two Arrays

#include <vector>
#include <unordered_set>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: 0(N)


class Solution {
public:
     std::vector<std::vector<int>> findDifference(std::vector<int>& nums1,
          std::vector<int>& nums2) 
     {
         
          std::unordered_set<int> set1{ begin(nums1),end(nums1) };
          std::unordered_set<int> set2{ begin(nums2),end(nums2) };

          std::vector<int> v1{}, v2{};

          for (const auto& i : set1)
               if (!set2.contains(i))
                    v1.push_back(i);

          for (const auto& i : set2)
               if (!set1.contains(i))
                    v2.push_back(i);


          return { v1,v2 };
         
     }
};