// 2022. Convert 1D Array Into 2D Array

#include <vector>


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1) ignoring return value

class Solution {
public:
     std::vector<std::vector<int>> construct2DArray(std::vector<int>& og, int m, int n) {

          std::vector<std::vector<int>> matrix{};
          if (og.size() != m * n) return matrix;

          for (int i{ 0 }; i < m; ++i)
               matrix.emplace_back(begin(og) + i * n, begin(og) + (i + 1) * n);
          
          return matrix;
     }
};

class Solution {
public:
     std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {

          std::vector<std::vector<int>> matrix{};
          if (original.size() != m * n) return matrix;

          std::vector<int> buffer{};

          for (int i{ 0 }; i < original.size(); ++i)
          {
               buffer.push_back(original[i]);

               if (buffer.size() == n) // column elements extracted
               {
                    matrix.push_back(buffer);
                    buffer.clear();
               }
          }
          return matrix;
     }
};