// 223. Rectangle Area
#include <iostream>


class Solution {
public:
     int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

          int areaA = (ax2 - ax1) * (ay2 - ay1);
          int areaB = (bx2 - bx1) * (by2 - by1);
          
          // Take max point in Horizontal axis
          int cx1 = std::max(ax1, bx1);
          int cy1 = std::max(ay1, by1);
          
          // min point on Vertical axis
          int cx2 = std::min(ax2, bx2);
          int cy2 = std::min(ay2, by2);

          // if they don't overlap width and Height should be 0
          int overlap= std::max(0, cx2 - cx1) * std::max(0, cy2 - cy1);

          return areaA + areaB - overlap;
     }
};