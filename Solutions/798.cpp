// 798. Smallest Rotation with Highest Score

#include <vector>

// TIME COMPLEXITY : 0(N)
// SPACE COMPELXITY : 0(N)

class Solution {
public:
     int bestRotation(std::vector<int>& nums) {
          
          int n = nums.size();
          std::vector<int> diff(n);

          for (int i{ 0 }; i < n; ++i)
          {
               int low = (i + 1) % n;
               int high = (i - nums[i] + n + 1) % n;

               ++diff[low];
               --diff[high];

               if (low > high) ++diff[0]; // wrapped

          }

          int k{ 0 }, max{ -1 }, score{ 0 };
          for (int i{ 0 }; i < n; ++i)
          {
               score += diff[i];
               if (score > max) {
                    max = score;
                    k = i; 
               }
          }
          return  k;
     }
};