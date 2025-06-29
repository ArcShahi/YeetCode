// 2154. Keep Multiplying Found Values by Two

#include <vector>


class Solution {
public:
	int findFinalValue(std::vector<int>& nums, int original)
	{

		for (int i{ 0 }; i < nums.size(); ++i)
		{
			if (nums.at(i) == original)
			{
				original *= 2;
				i = -1;
			}
		}
		return original;
	}
};