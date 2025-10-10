// 1160. Find Words That Can Be Formed by Characters

#include <string>
#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(N*K) ; k is the max len of a word
// SPACE COMPELXITY : O(1)


class Solution {
public:
     int countCharacters(std::vector<std::string>& words, std::string chars) {

          auto count_freq = [](const auto& str)
               {
                    std::vector<int> v(26, 0);
                    for (const auto c : str) ++v[c - 'a'];
                    return v;
               };

          const auto freq{ count_freq(chars) };
          int count{ 0 };

          for (const auto& word : words)
          {
               const auto wfreq{ count_freq(word) };
               bool can_form{ true };

               for (int i{ 0 }; i<26; ++i) 
                    if (wfreq[i] > freq[i])
                    {
                         can_form = false;
                         break;
                    }

               if (can_form) count += word.length();
          }
     
          return count;
     }
};