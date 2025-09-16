// 1828. Queries on Number of Points Inside a Circle

#include <vector>
#include <algorithm>


// TIME COMPLEXITY : O(N*M) ;
// SPACE COMPLEXITY ; O(M)

class Solution {
public:
     std::vector<int> countPoints(std::vector<std::vector<int>>& points,
          std::vector<std::vector<int>>& queries)
     {
          std::vector<int> out{};
          out.reserve(queries.size());  

          for (const auto& q : queries)  
          {
               int count{ 0 };
               for (const auto& p : points)
               {
                    if (inside_circle(p[0], p[1], q[0], q[1], q[2]))
                         ++count;
               }
               out.push_back(count);
          }
          return out;
     }

private:
     bool inside_circle(int x, int y, int h, int k, int r)
     {
          int dx = x - h;
          int dy = y - k;
          int dist_sq = dx * dx + dy * dy;
          int rad_sq = r * r;

          return dist_sq <= rad_sq;
     }
};

