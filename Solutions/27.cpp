// 27. Remove Element

#include <vector>
#include <algorithm>

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {

		int w{ 0 };

		for (auto& i : nums)
			if (i != val)
				nums[w++] = i;


		return w;
	}
};