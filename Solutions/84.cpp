// 84. Largest Rectangle in Histogram

#include <vector>

class Solution {
public:
     int largestRectangleArea(std::vector<int>& heights) {

          std::vector<int> stk{-1}; // Sentinel , NO BAR Smaller than current left
          const int n=heights.size() ;
          int area{ 0 };

          for (int i{ 0}; i <n; ++i)
          {  
               // while current is smaller than top of stack and stack is not -1
              while (stk.back()!=-1 && heights[i] < heights[stk.back()])
              {  
                   int h{ heights[stk.back()] }; stk.pop_back();
                   int l{ stk.back() };
                   int r{ i };
                   int width{ r - l - 1 };

                   area = std::max(area, h * width);
              }
               
              stk.push_back(i);      
          }
          //  Handle Flush ( reaming elements in stack )

          while (stk.back()!=-1)
          {
               int h{ heights[stk.back()] }; stk.pop_back();
               int l{ stk.back() };
               int r{n}; // Right Boundary is End
               int width{ r - l - 1 };

               area = std::max(area, h * width);
          }
          return area;
     }
};