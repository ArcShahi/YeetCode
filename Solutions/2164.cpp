// 2164. Sort Even and Odd Indices Independently

#include <vector>
#include <algorithm>


class Solution {
public:
     std::vector<int> sortEvenOdd(std::vector<int>& nums) {
          
          int N = nums.size();

          std::vector<int> even{};
          std::vector<int> odd{};
          even.reserve(N /2);
          odd.reserve(N /2);

          for (int i{ 0 }; i < N; ++i)
          {
               if (i & 1) odd.push_back(nums[i]);
               else even.push_back(nums[i]);
          }
         
          std::sort(begin(even), end(even));
          std::sort(rbegin(odd),rend(odd));

          // Merge back

          auto etr{ begin(even) };
          auto otr{ begin(odd) };

          for (int i{ 0 }; i < N; ++i)
          {
               if (i & 1)
               {
                    nums[i] = *otr++;
               }
               else
               {
                    nums[i] = *etr++;
               }
          }
          return nums;
     }
};

