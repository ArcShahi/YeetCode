// 1561. Maximum Number of Coins You Can Get

#include <vector>
#include <algorithm>

class Solution {
public:
     int maxCoins(std::vector<int>& piles) {

          std::ranges::sort(piles);

          int max{ 0 };
          auto itr{ end(piles) - 1 };

          for (int i{ 0 }; i < piles.size() / 3; ++i)
          {
               std::advance(itr, -2);
               max += *itr;
          }
          return max;
     }
};
