// 3146. Permutation Difference between Two Strings

#include <string>
#include <algorithm>
#include <unordered_map>
#include <numeric>

class Solution {
public:
     int findPermutationDifference(std::string s, std:: string t) {

          std::unordered_map<char, int> hashmap{};
          hashmap.reserve(s.size());

          for (int i{ 0 }; i < s.length(); ++i)
               hashmap[s[i]] = i;

          int sum{ 0 };
          for (int i{ 0 }; i < t.length(); ++i)
               sum += std::abs(hashmap[t[i]] - i);

          return sum;

     }
};