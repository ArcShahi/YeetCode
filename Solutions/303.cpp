// 303. Range Sum Query - Immutable

#include <vector>
#include <numeric>
#include <iterator>

class NumArray {
public:
     NumArray(std::vector<int>& nums) {
       
          cached.reserve(nums.size());
          std::partial_sum(begin(nums), end(nums), std::back_inserter(cached));
     }

     int sumRange(int left, int right) {

          int pre_right = cached[right];
          int pre_left = left > 0 ? cached[left - 1] : 0;

          return pre_right - pre_left;
     }

private:
     std::vector<int> cached{};
};