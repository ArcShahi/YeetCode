// 2057. Smallest Index With Equal Value

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)


class Solution {
public:
     int smallestEqual(std::vector<int>& nums) {

          int min{ 1111 }; // works as int min cuz 1<= N <=100
          
          for (int i{ 0 }; i < nums.size(); ++i)
               if (i % 10 == nums[i]) min = std::min(min, i);

          return min == 1111 ? -1 : min;

     }
};