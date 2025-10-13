// 2225. Find Players With Zero or One Losses
// 2225. Find Players With Zero or One Losses

#include <vector>
#include <algorithm>
#include <unordered_map>


// TIME COMPLEXITY : O(NlogN)
// SPACE COMPLEXITY : O(N)

class Solution {
     
public:
     std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
         
          const auto sz{ matches.size() };

          std::unordered_map<int,int> hmap{}; 
          for (const auto& match : matches)
          {
               hmap[match[0]];
               ++hmap[match[1]];
          }

          std::vector<int> noloss{}, oneloss{};
          noloss.reserve(sz);
          oneloss.reserve(sz);

          for (const auto& [player,loss] : hmap)
          {
               if (!loss) noloss.push_back(player);
               else if (loss == 1) oneloss.push_back(player);
          }

          std::ranges::sort(noloss);
          std::ranges::sort(oneloss);

          return { noloss,oneloss };
     }
   
};