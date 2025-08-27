// 2553. Separate the Digits in an Array

#include <vector>
#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPELXITY : O(N)

class Solution {
public:
     std::vector<int> separateDigits(std::vector<int>& nums)
     {
          std::vector<int> splited{};
          splited.reserve(nums.size() * 2); // assmuing every number is double digit
          for (auto& num : nums)
          {
               auto str{ std::to_string(num) };    
               for (const auto c : str)
                    splited.push_back(c - '0');         
          }

          return splited;
     }
};
