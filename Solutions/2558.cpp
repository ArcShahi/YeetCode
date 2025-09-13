// 2558. Take Gifts From the Richest Pile

#include <vector>
#include <queue>
#include <cmath>
#include <numeric>

// TIME COMPLEXITY : O(N + KlogN)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     long long pickGifts(std::vector<int>& gifts, int k) {
          
          std::priority_queue<int> pq{ begin(gifts),end(gifts) };

          while (k--) {
               pq.emplace(std::sqrt(pq.top())); pq.pop();

          }
         
          long long rem{ 0 };
          while (!pq.empty())
          {
               rem += pq.top();
               pq.pop();
          }

          return rem;
     }
};