// 973. K Closest Points to Origin

#include <vector>
#include <cmath>
#include <queue>

// TIME COMPLEXITY : O(nLogK)
// SPACE COMPLEXITY :O(n)

class Solution {
public:
     std::vector <std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
 
          // Lambda comparator for max-heap ( farthese point on top)
          auto cmp = [](const Info& a, const Info& b) { return a.distance < b.distance; };

          // Heapify
          std::priority_queue<Info, std::vector<Info>, decltype(cmp)>pq{cmp};
       
          for (const auto& p : points)
          {
               pq.emplace(p[0], p[1]);
               if (pq.size() > k) pq.pop(); // Keep size of k, pop farthest
          }
          
          std::vector<std::vector<int>> closest{};
          closest.reserve(k);

          while (!pq.empty())
          {
               auto it{ pq.top() }; pq.pop();
               closest.push_back({ it.x,it.y });
          }

          return closest;
     }

private:

     struct Info
     {
          int x{}, y{};
          double distance{};

          Info(int _x, int _y)
               :x{ _x }, y{ _y }
          {
               distance = std::hypot(x, y);
          }
     };
};