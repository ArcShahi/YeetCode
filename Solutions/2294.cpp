// 2294. Partition Array Such That Maximum Difference Is K
#include <vector>
#include <algorithm>


class Solution {
public:
	int partitionArray(std::vector<int>& nums, int k) {

		std::sort(begin(nums), end(nums));
		int count{ 1 };
		int reach{ nums[0] + k };

		for (const auto& i : nums) {
			if (reach < i) {
				++count;
				reach = i + k;
			}
		}
		return count;
	}
};