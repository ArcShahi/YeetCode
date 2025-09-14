// 1046. Last Stone Weight

#include <vector>
#include <queue>

// TIME COMPLEXITY : O(NlogN)
// SPACE COMPLEXITY: O(N)


class Solution {
public:
     int lastStoneWeight(std::vector<int>& stones) {

          std::priority_queue<int> pq{ begin(stones),end(stones) };

          while (pq.size()>1)
          {
               auto y{ pq.top() }; pq.pop();
               auto x{ pq.top() }; pq.pop();

               if (x != y) pq.push(y - x);
          }
          return pq.empty() ? 0 : pq.top();
     }
};