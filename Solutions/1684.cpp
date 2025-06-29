// 1684. Count the Number of Consistent Strings
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

class Solution {
public:
     int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {

          std::bitset<26> valid{};
          for (const auto& ch : allowed)
               valid[ch - 'a'] = true;

          const int count = std::ranges::count_if(words, [&](const auto& word) {
               return std::ranges::all_of(word, [&](char ch) {
                    return valid[ch-'a'];
                    });
               });

          return count;
          
     }
};