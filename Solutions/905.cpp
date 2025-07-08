// 905. Sort Array By Parity

#include <vector>

class Solution {
public:
	std::vector<int> sortArrayByParity(std::vector<int>& nums)
	{
		int l = 0;
		int r = nums.size() - 1;
		

		while (l<r)
		{
			if (!(nums[l] & 1))++l;
			else
			{
				std::swap(nums[l], nums[r--]);
			}
		}
	}
};