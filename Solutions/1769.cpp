// 1769. Minimum Number of Operations to Move All Balls to Each Box

#include <vector>
#include <string>


// TIME COMPLEIXTY : O(N)
// SPACE COMPLEXITY : O(N) 

class Solution {
public:
     std::vector<int> minOperations(std::string boxes) {

          int n = boxes.length();
          std::vector<int> vec{};
          vec.reserve(n);

          int moves{0}, count{0};
          for (const auto& i : boxes)
          {
               vec.push_back(moves);
               count += (i - '0');
               moves += count;
          }

          moves = count = 0;
          for (int i{ n - 1 }; i >= 0; --i)
          {
               vec[i] += moves;
               count += boxes[i] - '0';
               moves += count;
          }
          return vec;
     }
};