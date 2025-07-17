// 704. Binary Search

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(logn)
// SPACE COMPLEXITY : O(1)


class Solution {
public:
     int search(std::vector<int>& nums, int target) {
          auto it{ std::lower_bound(begin(nums),end(nums),target) };
          return (it != end(nums) && *it==target) ? std::distance(begin(nums),it) : -1;
     }
};


class Solution2{
public:
     int search(std::vector<int>& nums, int target) {
          if (nums.empty()) return -1;

          auto first{ begin(nums) };
          auto last{ end(nums) - 1 };

          while (first <= last)
          {
               auto mid{ first + (last - first) / 2 };

               if (*mid == target) return std::distance(begin(nums), mid);
               else if (*mid < target) first = mid + 1;
               else last = mid - 1;
          }
          return -1;
     }
};


// USE TOP only if already know how to implement binary search.