// 485. Max Consecutive Ones
#include <vector>

class Solution {
public:
	int findMaxConsecutiveOnes(std::vector<int>& nums)
	{
		// ios_base::sync_with_stdio(false); ( Add this when Runtime Over 5ms )
		int count = 0;
		int cache = 0;

		for (auto& i : nums)
		{
			if (i == 1)
			{
				cache++;
				count = std::max(count, cache);
			}
			else
			{
				cache = 0;
			}

		}
		return count;
	}
};

