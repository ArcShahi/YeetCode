// 268. Missing Number
#include <vector>
#include <numeric>

// Thing to pay attention is that elements in nums are all Distinct
class Solution {
public:
     int missingNumber(std::vector<int>& nums) {

          int n = nums.size();
         
          // So the Total sum of nums should be equal to this
          int total = (n * (n + 1) / 2);

           // Missing number = Total - what's in nums
          return total - std::accumulate(begin(nums), end(nums), 0);
         

     }
};