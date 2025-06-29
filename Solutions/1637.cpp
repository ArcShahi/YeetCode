// 1637. Widest Vertical Area Between Two Points Containing No Points
#include <vector>
#include <algorithm>


class Solution {
public:
     int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {

          int max_dis{ 0 };
          std::vector<int> vecx{};
          vecx.reserve(points.size());

          for (const auto& p : points)
               vecx.push_back(p[0]);
          
          std::ranges::sort(vecx);
          
          for (int i{ 1 }; i < vecx.size() - 1; ++i)
          {
               max_dis = std::max(max_dis, vecx[i] - vecx[i - 1]);
          }
          return max_dis;
     }
};
