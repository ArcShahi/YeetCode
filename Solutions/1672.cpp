// 1672. Richest Customer Wealth

#include <vector>
#include <numeric>

class Solution {
public:
     int maximumWealth(std::vector<std::vector<int>>& accounts) {
           int rich{ 0 };

          for (const auto& i : accounts)
          {
               auto money = std::accumulate(begin(i), end(i), 0);
               rich = std::max(money, rich);
          }

          return rich;
     }
};