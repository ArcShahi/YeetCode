// 2616. Minimize the Maximum Difference of Pairs

#include <vector>
#include <algorithm>
#include <span>

class Solution {
public:
     int minimizeMax(std::vector<int>& nums, int p) {

          if (p == 0) return 0;
          std::ranges::sort(nums);

          int left{ 0 };
          int right{ nums.back() - nums.front() };

          while (left< right)
          {
               auto mid = left + (right - left) / 2;

               if (are_pairs(nums,mid,p))
                    right = mid;
               else
                    left = mid + 1;     

          }
          return left;
     }

private:
     bool are_pairs(std::span<const int> v,const int lim,const int p)
     {
          int count{ 0 };
          for ( int i{ 0 }; i < v.size() - 1;)
          {
               if (v[i + 1] - v[i] <= lim)
               {
                    ++count;
                    i += 2;
               }
               else
                    ++i;

               if (count >= p) return true;
          }
          return false;
     }
};
