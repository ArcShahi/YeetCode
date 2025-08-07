// 1720. Decode XORed Array

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N) 

class Solution {
public:
     std::vector<int> decode(std::vector<int>& encoded, int first) {

          int n = encoded.size();
          std::vector<int> og(n+1);
          og.front() = first;

          for (int i{ 0 }; i < n; ++i)
               og[i + 1] = encoded[i] ^ og[i];

          return og;
     }
};