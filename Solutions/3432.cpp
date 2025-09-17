// 3432. Count Partitions with Even Sum Difference


#include <vector>
#include <numeric>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int countPartitions(std::vector<int>& nums){

          int total{ std::accumulate(begin(nums),end(nums),0) };
          int leftsum{ 0 };
          int count{ 0 };

          //  we skip the last index
          for (int i{ 0 }; i < nums.size()-1; ++i)
          {
               leftsum += nums[i];
               if((leftsum-total-leftsum)%2==0) ++count;
          }
          return  count;
     }
};


class Solution {
public:
     int countPartitions(std::vector<int>& nums){

          int total{ std::accumulate(begin(nums),end(nums),0) };
          int leftsum{ 0 };
 
          //  we skip the last index
          return std::count_if(begin(nums), end(nums) - 1, [&](auto& x) {
               leftsum += x;
               return (leftsum - total - leftsum) % 2 == 0;
               });

     }
};