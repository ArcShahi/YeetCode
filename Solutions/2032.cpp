// 2032. Two Out of Three

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <array>


class Solution {
public:
     std::vector<int> twoOutOfThree(std::vector<int>& nums1, std::vector<int>& nums2,
          std::vector<int>& nums3) {


          std::unordered_map<int, int> freq{};

          auto add = [&](const auto& nums)
               {
                    std::unordered_set s(begin(nums), end(nums));
                    for (const auto x : s) ++freq[x];
               };

          add(nums1);
          add(nums2);
          add(nums3);

          std::vector<int> v{};
          for (const auto& [num, count] : freq)
               if (count >= 2)v.push_back(num);

          return v;
     }
};



class Solution {
public:
     std::vector<int> twoOutOfThree(std::vector<int>& nums1, std::vector<int>& nums2,
          std::vector<int>& nums3) {

          std::array<int, 101> bits{}; // all zero-initialized

          for (int n : nums1) bits[n] |= 1 << 0;
          for (int n : nums2) bits[n] |= 1 << 1;
          for (int n : nums3) bits[n] |= 1 << 2;

          std::vector<int> v{};

          for (int i = 1; i <= 100; i++) {
               if (bits[i] == 3 || bits[i] >= 5) v.push_back(i);
          }

          return v;
     }
};
