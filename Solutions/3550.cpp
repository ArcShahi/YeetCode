// 3550. Smallest Index With Digit Sum Equal to Index

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int smallestIndex(std::vector<int>& nums) {
          // Anon. Fun 
          auto digit_sum = [](int x) {
               if (x < 10) return x;
               int sum{ 0 };
               for (; x > 0; x /= 10) sum +=(x%10);
               return sum;
               };

          for (int i{ 0 }; i < nums.size(); ++i)
               if (digit_sum(nums[i]) == i) return i;
          
          return -1;
     }
};
