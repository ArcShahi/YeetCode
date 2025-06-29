// 167. Two Sum II - Input Array Is Sorted


#include <vector>

class Solution {
public:
     std::vector<int> twoSum(std::vector<int>& numbers, int target) {

          int l = 0;
          int r = numbers.size() - 1;

          while (l<r)
          {
               if (numbers[l] + numbers[r] == target) return { l + 1,r + 1 };
               else if (numbers[l] + numbers[r] < target) ++l;
               else --r;
          }

          return { -1,-1 };
     }
};

// Input array is sorted