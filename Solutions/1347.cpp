// 1347. Minimum Number of Steps to Make Two Strings Anagram

#include <string>
#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int minSteps(std::string s, std::string t) {

          std::vector<int> v(26, 0);

          for (const auto c : s)
               ++v[c-'a'];

          for (const auto c : t)
               --v[c-'a'];

          int steps{ 0 };
          for (size_t i{ 0 }; i < 26; ++i)
               if (0 < v[i]) steps += v[i];

          return steps;
     }
};