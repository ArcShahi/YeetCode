// 26. Remove Duplicates from Sorted Array

#include <vector>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums)
	{
		if (nums.empty())
			return 0;

		int itr{ 0 };

		for (int i{ 1 }; i < nums.size(); ++i)
		{
			if (nums[i] != nums[i - 1])
			{
				nums[++itr] = nums[i];
			}
		}

		return itr + 1;
	}
};
