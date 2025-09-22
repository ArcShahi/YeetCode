// 389. Find the Difference

#include <array>
#include <string>


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     char findTheDifference(std::string s, std::string t) {

          std::array<int, 26>arr{};

          for (const auto c : s)
               ++arr[c - 'a'];

          for (const auto c : t)
               --arr[c - 'a'];

          for (int i{ 0 }; i < arr.size(); ++i)
               if (arr[i] < 0) return 'a' + i;
          
          return ' ';
     }
};