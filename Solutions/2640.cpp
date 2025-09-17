// 2640. Find the Score of All Prefixes of an Array

#include <vector>


// TIME COMPELXITY : O(N)
// SPACE COMPELXITY : O(1) ; if ignoring return value

class Solution {
public:
     std::vector<long long> findPrefixScore(std::vector<int>& nums) {

          int n = nums.size();
          std::vector<long long> arr(n, 0);

          int max{ -69420 };// works as initial max

          long long score{ 0 };
          for (int i{ 0 }; i < n; ++i)
          {
               max = std::max(max, nums[i]);
               // We can also :  arr[i] = nums[i] + max + (i == 0 ? 0 : arr[i - 1]);
               long long sum = nums[i] + max;
               arr[i] = sum + score;
               score += sum;
          }

          return arr;
     }
};