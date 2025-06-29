// 2011. Final Value of Variable After Performing Operations
#include <vector>
#include <string>

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXIY : O(1)


class Solution {
public:
     int finalValueAfterOperations(std::vector<std::string>& operations) {
          int x{ 0 };
          for (const auto& op : operations)
               x += (op[1] == '+') ? 1:-1;
 
          return x;
     }
};


