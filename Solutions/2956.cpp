// 2956. Find Common Elements Between Two Arrays

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bitset>

// Input Size is smaller so we can use Bitset
// TIME COMPLEIXTY : O(M+N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {

          std::bitset<101> b1{}, b2{};
          for (const auto& i : nums1)b1.set(i);
          for (const auto& i : nums2)b2.set(i);

          int ans1{ 0 };
          for (const auto& i : nums1)
               if (b2[i]) ++ans1;

          int ans2{ 0 };
          for (const auto& i : nums2)
               if (b1[i]) ++ans2;

          return { ans1,ans2 };
     }
};

// TIME COMPLEXITY : O(M+N)
// SPACE COMPLEXITY : O(M+N)
class Solution2 {
public:
     std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {

          std::unordered_map<int, int> m1{}, m2{};

          for (const auto& i : nums1) ++m1[i];
          for (const auto& i : nums2) ++m2[i];

          int ans1{};
          for (const auto& [k, v] : m1)
               if (m2.count(k)) ans1 += v;

          int ans2{};
          for (const auto& [k, v] : m2)
               if (m1.count(k)) ans2 += v;

          return { ans1, ans2 };
     }
};
