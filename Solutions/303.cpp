// 303. Range Sum Query - Immutable

#include <vector>
#include <algorithm>


class NumArray {
public:
     NumArray(std::vector<int>& nums) {
       
          int sum{ 0 };
          cached.reserve(nums.size()); 
          std::ranges::transform(nums, end(cached), [&](int x) {
               sum += x;return sum; 
               });
     }

     int sumRange(int left, int right) {

          int pre_right = cached[right];
          int pre_left = left > 0 ? cached[left - 1] : 0;

          return pre_right - pre_left;
     }

private:
     std::vector<int> cached{};
};