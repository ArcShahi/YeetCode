// 283. Move Zeroes

#include <vector>

class Solution {
public:
	void moveZeroes(std::vector<int>& nums) {


		auto itr = begin(nums);

		for (auto& i : nums)
		{
			if (i)
			{
				std::swap(i, *itr);
				++itr;
			}
		}
	}
};

