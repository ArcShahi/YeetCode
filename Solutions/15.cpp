// 15. 3Sum

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {

public:
    /* Solution()
     {
          std::ios::sync_with_stdio(false);
          std::cin.tie(nullptr);
     }*/
public:
     std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

          std::vector<std::vector<int>> triplet{};
         
          std::ranges::sort(nums);

          for (int i{ 0 }; i < nums.size(); ++i)
          {
               // skip duplicates
               if (i > 0 && nums[i] == nums[i - 1]) continue;

               int first = nums[i];

               int l = i + 1;
               int r = nums.size() - 1;

               while (l<r)
               {
                    if (first + nums[l] + nums[r] == 0)
                         triplet.push_back({ first,nums[l],nums[r] });

                    else if (first + nums[l] + nums[r] < 0)  ++l;
                        
                    else  --r;
                         
               }

          }

          return triplet;
     }
};

