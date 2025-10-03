// 349. Intersection of Two Arrays

#include <vector>
#include <unordered_set>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(N)

class Solution {
public:
     std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {

          std::unordered_set s1(begin(nums1), end(nums1));
          std::unordered_set<int> s2{};
          for (const auto& i : nums2)
               if (s1.contains(i)) s2.insert(i);

          std::vector<int> v{};
          for (const auto& e : s2)
               if (s1.contains(e)) v.push_back(e);

          return v;
          
     }
};

// TODO WITH SORTED APPORACH