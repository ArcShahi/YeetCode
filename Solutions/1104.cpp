// 1104. Path In Zigzag Labelled Binary Tree

#include <vector>
#include <algorithm>
#include <cmath>

// TIME COMPLEXITY : O(log(lable)
// SPACE COMPLEXITH : O(log(label) // constant if ignoring the return value
class Solution {
public:
     std::vector<int> pathInZigZagTree(int label) {
          int level = std::log2(label) + 1;
          std::vector<int> path(level);

          for (int i = level - 1; i >= 0; --i) {
               path[i] = label;
               const int node = (1 << (i + 1)) + (1 << i) - 1; // 2^(i+1)+2^i -1
               label = node - label; // Gives Parent Node
               label /= 2;
          }
          return path;
     }
};
