// 1. Two Sum


#include <vector>
#include <unordered_map>
class Solution {
public:

	std::vector<int> twoSum(std::vector<int>& vec, int target)
	{
		std::unordered_map<int, int> hashmap{};

		for (int i{ 0 }; i < vec.size(); ++i)
		{
			int value{ target - vec[i] };
		
			if (hashmap.count(value))
				return { hashmap[value],i };

			hashmap[vec[i]] = i;
		}
		return { -1,-1 };

	}

};