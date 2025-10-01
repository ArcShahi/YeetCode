// 3340. Check Balanced String

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     bool isBalanced(std::string num) {

          int odd_sum{ 0 }, even_sum{ 0 };

          for (size_t i{ 0 }; i < num.length(); ++i)
          {
               auto sum = num[i] - '0';
               if (i & 1) odd_sum += sum;
               else even_sum += sum;
          }
          return odd_sum == even_sum;
     }
};