// 448. Find All Numbers Disappeared in an Array
#include <vector>

class Solution 
{
public:
	std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
	{
		std::vector<int> lost{};

		for (auto& i : nums)
		{
			auto x = abs(i) - 1;
			if (0 < nums[x])
			{
				nums[x] = -nums[x];
			}
		}

		for (int i{ 0 }; i < nums.size(); ++i)
		{
			if (0 < nums[i])
			{
				lost.push_back(i + 1);
			}
		}
		return lost;
	}
};