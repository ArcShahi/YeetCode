// 11. Container With Most Water

#include <vector>
#include <iostream>
// TIME COMPLEXITY : O(n) 

class Solution {
public:
     int maxArea(std::vector<int>& height)
     {
          int l = 0;
          int r = height.size() - 1;

          auto area{ 0 };
          auto width{0};
          
        while (l<r)
        {
               width = r - l;
               auto high{ std::min(height[l],height[r]) };
               area = std::max(high * width, area);
              
               if (height[l] < height[r]) ++l;
               else --r;
        }
  
          return area;
     }
};

// Much cleaner
class Solution2 {
public:
     int maxArea(std::vector<int>& height)
     {
          auto l{ begin(height) };
          auto r{ end(height) - 1 };
          auto area{ 0 };
          auto width{ 0 };

          while (l < r)
          {
               width = std::distance(l, r);
               auto high{ std::min(*l,*r) };
               area = std::max(high * width, area);

               if (*l < *r) ++l;
               else --r;
          }
          return area;
     }
};
